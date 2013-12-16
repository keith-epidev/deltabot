var cmds = [];
var axies = {X:0,Y:0,Z:0,E:0,F:0};

var scale = 1;
var phy_offset = 0;

parse_file = function(data){


	data = data.split("\n");
	for(var i = 0; i < data.length; i++)
		parse_line(data[i]);


	//	parse_cart(data);

	
	for(var i = 0; i < cmds.length; i++)
		cmds[i][4] = calc_change(i);


	for(var i = 0; i < cmds.length; i++)
		cmds[i] = prep_str(i);

	for(var i = 0; i < cmds.length; i++)
		cmds[i] += " "+calc_checksum(i);

	return cmds;
}



prep_str = function(index){
	var str =  "aprox";
	for(var i = 0; i < 5; i++)
	str += " "+cmds[index][i].toFixed(2);

	return str;
}

calc_checksum = function(i){
	var checksum = 0;

	for(var j = 0 ; j < cmds[i].length; j++)
		checksum += cmds[i].charCodeAt(j);

	return checksum;
}




get_direction = function(index){
	return [cmds[index][1]<0,cmds[index][2]<0,cmds[index][3]<0];	
}

is_same_direction = function(a,b){
	return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}



calc_change = function(index){
	//append distance till next direction flip
	var current_dir = get_direction(index);

	var offset = 0;
	var displacement = 0;
	while(true){
	//	console.log(current_dir)
	//	console.log(get_direction(index+offset))



		if( !is_same_direction(current_dir,get_direction(index+offset)) )	
			break;

		displacement += cmds[index+offset][0];

		if(cmds.length-1 > index+offset)
		offset++;
		else
		break;
	}
		
	//	console.log('d='+displacement+" o="+offset);
	return displacement;

}



parse_cart = function(data){
	var cart = JSON.parse(data);
	

		cart.unshift([0,0,160]);
		cart.push([0,0,160]);


	for(var i = 0; i < cart.length; i++){	
		var coord = cart[i];

		var last = clone(axies);

		axies.X = coord[0];
		axies.Y = coord[1];
		axies.Z = coord[2];


		console.log(i);
		console.log(JSON.stringify(axies));

		var last_heights = calc_heights([last.X,last.Y,last.Z]);
		var new_heights = calc_heights([axies.X,axies.Y,axies.Z]);

		var speeds = calc_speeds(new_heights,last_heights);

		cmds.push(speeds);
			
	}



}



parse_line = function(line){

	//remove comments
	var r = new RegExp("(;.*)");
	line = line.replace(r,"").trim();

	if(line=="")
	return //ignore empty cmd
		
	console.log(line);
	cmd = line.split(" ");	

	switch(cmd[0]){
	case "G1":
		var last = clone(axies);


		for(var i = 1; i < cmd.length; i ++){
			var axis  = cmd[i].substr(0,1);
			var number = cmd[i].substr(1,cmd[i].length);
			if(axis == 'X' || axis == 'Y')
			number = (parseFloat(number) + phy_offset)*scale;
			else
			number = parseFloat(number)*scale;

			axies[axis] = number;
		}

		var last_heights = calc_heights([last.X,last.Y,last.Z]);
		var new_heights = calc_heights([axies.X,axies.Y,axies.Z]);
//	console.log(last_heights);
//	console.log(new_heights);
	console.log(axies);
		var speeds = calc_speeds(new_heights,last_heights);

		cmds.push(speeds);
	}





}
