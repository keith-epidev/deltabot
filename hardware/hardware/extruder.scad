$fn = 30;

module extruder(){
rotate([180,0,0]) nozzle();
	barrel();
	translate([0,0,20]) brass_insert();
}


module barrel(){
color("black")
	difference(){
		cylinder(r = 8, h= 39.5 );
		//inner channel
		cylinder(r = 3, h= 80, center = true );
		
		translate([0,0,30]) barrel_ring();


	}
}

module barrel_ring(){
color("black")
	difference(){
		cylinder(r = 8.1, h= 4.6 );
		//inner channel
		
		cylinder(r = 6, h=10 ,center = true);
		

	}


}



module nozzle(){
color("silver"){



translate([-6,-16/2,0])
cube([18.25,16,9.3]);
translate([0,0,9.3]){
cylinder(h = 2,r = 7.6/2);
translate([0,0,2]){
cylinder(2.3,7.6/2,1.74/2);
translate([0,0,2.3]) cylinder(h = .8, r =1.74/2);
}
}
}
}


module brass_insert(){
	color("gold")
	difference(){
	cylinder(r = 3, h= 20 );
	cylinder(r = 2, h= 20 );
	}
}


module top_tube_fix(){
color("white"){
difference(){
union(){
translate([0,0,10])
cylinder(r=8,h=10,center=true);

difference(){
	union(){
	//base
	cylinder(r=12,h=10);

	for(j = [0:2])
	rotate([0,0,j*360/3]) translate([-5 ,7,0]) 
	union(){
	cube([10,5,5]);
	translate([5,5,0])
	cylinder(r=5,h=5);
	}
	}
	

	cylinder(r=8,h=12,center=true);

//stand off holes
for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,0])
cylinder(r=1.7,h=11,center=true);

//bores for stand off
for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,10.5])
cylinder(r=3.5,h=11,center=true);

}

}
cylinder(r=3.2,h=39,center=true);
translate([0,0,-4])
cylinder(r=5,h=8);
}
}}


module top_end_clamper(){
height = 17;

color("white"){
difference(){
	union(){
	//base
	cylinder(r=12,h=height);

	for(j = [0:2])
	rotate([0,0,j*360/3]) translate([-5 ,7,0]) 
	union(){
	cube([10,5,height]);
	translate([5,5,0])
	cylinder(r=5,h=height);
	}
	}
	

	cylinder(r=4,h=height*2-4,center=true);

//stand off holes
for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,0])
cylinder(r=1.7,h=height*3,center=true);

//clamp holes
for(j = [0:2])
for(k = [4,13])
translate([0,0,k])
rotate([30+60+j*360/3,90,0]) cylinder(r=1.7,h=20);

}


}
}


module top_end(){
height = 4.4;

color("white"){
difference(){
	union(){
	//base
	cylinder(r=12,h=height);

	for(j = [0:2])
	rotate([0,0,j*360/3]) translate([-5 ,7,0]) 
	union(){
	cube([10,5,height]);
	translate([5,5,0])
	cylinder(r=5,h=height);
	}
	}
	

	cylinder(r=6,h=12,center=true);

//stand off holes
for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,0])
cylinder(r=1.5,h=11,center=true);
}

}
}

module top_end_closed(){
color("white")
intersection(){
	union(){

	translate([0,0,-.1]){
//	cylinder(r=6,h=6);

	rotate([0,0,30])
	translate([0,-6,0])
	cube([12,12,6]);
	}


	rotate([0,0,30])
	translate([0,-20,-1])
	cube([15,40,3]);
}

	top_end();

}

}



module top_end_open(){
color("white")
difference(){
	top_end();


	translate([0,0,-.1]){
	cylinder(r=6,h=6);

	rotate([0,0,30])
	translate([0,-6,0])
	cube([12,12,6]);
	}


	rotate([0,0,30])
	translate([0,-20,-1])
	cube([15,40,3]);
}

}



module platform(){
color("white"){
difference(){
	union(){
	//base
	cylinder(r=15,h=8);

	for(j = [0:2])
	rotate([0,0,j*360/3])
	translate([0 ,7,0])
	traxxis_mount();
	}


//peek tube bore
cylinder(r=10,h=24,center=true);

//stand off holes
for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,0])
cylinder(r=1.5,h=24,center=true);

}
}
}


module traxxis_mount(){

color("white"){
difference(){
union(){
translate([-3,5,0]) cube([6,15,8]);

for(i = [-1,1]){
translate([i*(7+6),0,0]) translate([-3,0,0]) cube([6,20,8]);
}
}


translate([-20,15,4])
rotate([0,90,0]){
cylinder(r=1.75,h=40);
//bores
translate([0,0,2]) cylinder(r=3.5,h=3);
translate([0,0,35]) cylinder(r=3.5,h=3);




}


translate([0,20,8]) 
rotate([180,90,0])
fillet(3,40);

translate([0,20,0]) 
rotate([90,0,270])
fillet(3,40);
//translate([10,12,0]) fillet_face(2,4,6,12);
//translate([-16,12,0]) fillet_face(2,4,6,12);
//translate([-3,12,0]) fillet_face(2,4,6,12);
}


}

}
//traxxis_mount();


module traxxis_ball(){
color("silver"){
	

	sphere(r=5.8/2);

for(i = [0,180])	
rotate([0,0,i])
translate([3.5,0,0])
	difference(){
	sphere(r=5.8/2);
	translate([0,-3,-3])
	cube([6,6,6]);
	}
}
}


module platform_assembled(){
platform();

for(j = [0:2])
rotate([0,0,j*360/3])
	for(i = [-1,1])
	translate([i*6.5 ,22,4])
	traxxis_ball();

for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,5])
dodgy_standoffs();


translate([0 ,0,28]){
top_end_open();
top_end_closed();
}
translate([0 ,0, 28+4.6]) top_tube_fix();

}







module dodgy_standoffs(){
color("silver"){

cylinder(r=1.6,h=23);


}
}

/*
translate([0,0,-2])
extruder();
platform_assembled();
*/
