function gen_str(x,y,z){

	var pos_a = calc_pos(x,y,z);
	var speeds = calc_speeds(pos_a[0],pos_a[1], pos_a[2]);


	var str = "aprox";
	for(var i = 0; i < speeds.length; i++)
		str += " "+speeds[i];


	return str+"\r";
}

dist = function(a,b){
	return Math.sqrt( Math.pow(a,2) + Math.pow(b,2) );
}


calc_heights = function(p){
	var x = p[0];
	var y = p[1];
	var z = p[2];

console.log(p);

	var conv = 32/0.21;

//	var r = 346.55;
	var r = 128;
	var r2 = Math.pow(r,2);
	var D = 79 
	var pr = 22;//26.5;

	var root3 = Math.sqrt(3);
	var root32 = Math.sqrt(3)/2;
	/*
	console.log("r="+r);
	console.log("r2="+r2);
	console.log("D="+D);
	console.log("x="+x);
	console.log("y="+y);
	console.log("z="+z);
	console.log(D);
*/

//fix math!
        var a1 = z + Math.sqrt( r2 - Math.pow( dist( x, (y +pr) - D ),2) );
        var a2 = z + Math.sqrt( r2 - Math.pow( dist( (x - root3*pr/2) + root3*D/2, (y - 0.5*pr) + D/2 ),2) );
        var a3 = z + Math.sqrt( r2 - Math.pow( dist( (x + root3*pr/2) - root3*D/2, (y - 0.5*pr) + D/2 ),2) );


    //    var a1 = z + Math.sqrt( r2 - Math.abs( Math.pow(x,2) + Math.pow(y - D - pr,2) )); 
//        var a2 = z + Math.sqrt( r2 - Math.abs( Math.pow(x - pr*root32 - (-D*root32),2) + Math.pow(y - pr/2 - ( -D/2),2)) ) 
  //      var a3 = z + Math.sqrt( r2 - Math.abs( Math.pow(x + pr*root32 - (-D*root32),2) + Math.pow(y - pr/2 - ( -D/2),2)) ) 



/*
        var a1 = z + Math.sqrt( r2 - Math.pow( dist( x, (y +pr) - D ),2) );
        var a2 = z + Math.sqrt( r2 - Math.pow( dist( (x-.5*pr ) + root3*D/2, (y - root32*pr) + D/2 ),2) );
        var a3 = z + Math.sqrt( r2 - Math.pow( dist( (x+.5*pr) - root3*D/2, (y - root32*pr ) + D/2 ),2) );

	console.log(a1);
	console.log(a2);
	console.log(a3);
*/
/*
	a1 *= conv;
	a2 *= conv;
	a3 *= conv;
*/	
	return [a1,a2,a3];
//	return calc_speeds(a1,a2,a3);
}

calc_speeds = function(n,o){

	var conv = 32/0.21;
                //target is 300 height
                var a0_disp = n[0] - o[0];
                var a1_disp = n[1] - o[1];
                var a2_disp = n[2] - o[2];
		var dist = 0;
                
	//	o[0] = n[0];
	//	o[1] = n[1];
	//	o[2] = n[2];


                var a0_dist = Math.abs(a0_disp);
                var a1_dist = Math.abs(a1_disp);
                var a2_dist = Math.abs(a2_disp);
                



                if(a0_dist >= a1_dist && a0_dist >= a2_dist){
                        var a0_speed = a0_disp/a0_dist;
                        var a1_speed = a1_disp/a0_dist;
                        var a2_speed = a2_disp/a0_dist;
                        dist = a0_dist;
                }else
                if(a1_dist >= a0_dist && a1_dist >= a2_dist){
                        var a0_speed = a0_disp/a1_dist;
                        var a1_speed = a1_disp/a1_dist;
                        var a2_speed = a2_disp/a1_dist;
                        dist = a1_dist;
                }else
                if(a2_dist >= a0_dist && a2_dist >= a1_dist){
                        var a0_speed = a0_disp/a2_dist;
                        var a1_speed = a1_disp/a2_dist;
                        var a2_speed = a2_disp/a2_dist;
                        dist = a2_dist;
                }
/*
                a0_speed = 1/a0_speed;
                a1_speed = 1/a1_speed;
                a2_speed = 1/a2_speed;
*/
           /*     
                a0_speed *= 100;
                a1_speed *= 100;
                a2_speed *= 100;
             
	*/
	  // dist *= 100;    


		a0_speed = isFinite(a0_speed) ? a0_speed : 0;
		a1_speed = isFinite(a1_speed) ? a1_speed : 0;
		a2_speed = isFinite(a2_speed) ? a2_speed : 0;


	dist *= conv;

/*
		var dist = dist.toFixed(4);
		var a0_speed  = a0_speed.toFixed(4);
		var a1_speed  = a1_speed.toFixed(4);
		var a2_speed  = a2_speed.toFixed(4);
*/
/*
                console.log(a0_speed);
                console.log(a1_speed);
                console.log(a2_speed);	
		console.log(dist);
*/

		return [dist,a0_speed,a1_speed,a2_speed];


}
