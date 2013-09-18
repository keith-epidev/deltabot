
module hex(s,d=14){
	linear_extrude(s)
	hull(){
		for(i = [0:5])
		rotate([0,0,i*360/6])
		translate([d/2,0,0]) 
		circle([1,1]);
	}
}



module ring(height,colour,outer,inner){
color(colour){
	difference(){
	cylinder(r=outer,h=height);

	translate([0,0,-.5]) cylinder(r=inner,h=height+1);
	}
}
}



