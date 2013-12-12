	var r = 128;
	var r2 = Math.pow(r,2);
	var D = 79 
	var pr = 22;//26.5;

	var root3 = Math.sqrt(3);
	var root32 = Math.sqrt(3)/2;

	z = 0;
	y = 94;
	x = 94;

        var a1 = z + Math.sqrt( r2 - Math.abs( Math.pow(x,2) + Math.pow(y - D - pr,2) ) ); 
        var a2 = z + Math.sqrt( r2 - Math.abs( Math.pow(x - pr*root32 - (-D*root32),2) + Math.pow(y - pr/2 - ( -D/2),2)) ) 
        var a3 = z + Math.sqrt( r2 - Math.abs( Math.pow(x + pr*root32 - (-D*root32),2) + Math.pow(y - pr/2 - ( -D/2),2)) ) 


	console.log( Math.pow(x,2) + Math.pow(y - D - pr,2)) ;

console.log(a1);
console.log(a2);
console.log(a3);
