function load_folder(folder){
	var files = fs.readdirSync(folder);
	for(var i = 0; i < files.length; i++){
		load(folder+'/'+files[i]);
	}

}


function load(file){
	try{
		var t = eval(fs.readFileSync(file)+'');
	}catch(E){		
		console.log("[!] Could not open '"+file+"' : "+E);
	}
}

