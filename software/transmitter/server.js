//load in node modules
var fs = require('fs');
var execSync = require('exec-sync');
var util = require('util');
var exec = require('child_process').exec;
var clone = require('clone');

//custom tools load
eval(fs.readFileSync('utils/loader.js')+'');
load_folder('utils');
load('gcode.js');
load('dda.js');

//arg check
if(process.argv.length < 3){
	console.log("Missing file argument");
	process.exit(1);
}


//splash
//clear();
console.log("-=[ Deltabot Transmitter ]=-");
console.log("Version 0.1 Keith Brown 2013");
console.log("La Trobe University - ELE4PRO")
console.log("-----------------------------")


//opening file
var file = process.argv[2];
try{
console.log("Loading file '"+file+"'")
var data = fs.readFileSync(file).toString();
}catch(E){
console.log("[!] Could not open file");
process.exit(1);
}

//parse gcode
var cmds = parse_file(data);

console.log(cmds);
//uart port
var uart = "/dev/ttyUSB0";
var baud = 38400;
console.log("Setting UART baud rate of "+baud);
try{execSync("stty -F "+uart+" "+baud);}catch(E){console.log(E)};
console.log("Opening UART streams")
var output = fs.createWriteStream(uart);
console.log("OUT [OK]")
var input = fs.ReadStream(uart);
console.log("IN  [OK]")


console.log("Starting...");
console.log("------------");

var index = 0;
var checksum_fails = 0;
var messages_sent = 0;
var time_started = Date.now();


//init printer
cmds.unshift("home");

input.on('data',function(d){
	var d = d.toString();
	console.log("[!] "+d);

		//okay to receive
		if(d.indexOf(">") != -1) {
			//hang on last message checksum faulted	
			if(d.indexOf("@") != -1) {
				console.log("[x] Checksum failed")
				checksum_fails++;
				index--;
			}

			if(index > cmds.length){
				exit();
			}

			var cmd = cmds[index];
			console.log("[~] "+cmd);
			//setTimeout(function(){
			output.write(cmd+"\r");
			//},2000);
			messages_sent++;
			index++;


		}
});




function exit(){
	var time_finished = Date.now();
	var difference = time_finished - time_started;
	var hours = Math.floor(difference / 36e5),
	    minutes = Math.floor(difference % 36e5 / 60000),
	    seconds = Math.floor(difference % 60000 / 1000);
	

	console.log('------------------')
	console.log('finished!');
	console.log(messages_sent+" lines were sent");
	console.log(checksum_fails+" checksum fails occured");
	console.log("It took "+hours+" hours, "+minutes+" minutes and "+seconds+" seconds");


	process.exit(0)


}

