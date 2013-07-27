module extruder(){
	barrel();
	nozzle();
	translate([0,0,41]) brass_insert();
}


module barrel(){
color("black")
translate([0,0,2]){
difference(){
cylinder(r = 8, h= 58.27 );
cylinder(r = 3, h= 60 );
}}
}

module nozzle(){
color("silver"){


translate([-15,-10,0])
cube([30,20,8]);

translate([0,0,-4])
cylinder(4,0.4,6);

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
translate([0,0,6])
cylinder(r=8,h=6,center=true);

difference(){
	union(){
	//base
	cylinder(r=12,h=5);

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
cylinder(r=1.5,h=11,center=true);
}

}
cylinder(r=3.2,h=21,center=true);
translate([0,0,-4])
cylinder(r=5,h=10);
}
}}


module top_end(){
color("white"){
difference(){
	union(){
	//base
	cylinder(r=12,h=5);

	for(j = [0:2])
	rotate([0,0,j*360/3]) translate([-5 ,7,0]) 
	union(){
	cube([10,5,5]);
	translate([5,5,0])
	cylinder(r=5,h=5);
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
cylinder(r=10,h=11,center=true);

//stand off holes
for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,0])
cylinder(r=1.5,h=11,center=true);

}
}
}


module traxxis_mount(){

color("white"){
difference(){
union(){
translate([-3,5,0]) cube([6,9,8]);
for(i = [-1,1]){
translate([i*10,0,0]) translate([-3,0,0]) cube([6,14,8]);
}
}

translate([-20,10,4])
rotate([0,90,0])
cylinder(r=2,h=40);

}


}

}



module platform_assembled(){
platform();

for(j = [0:2])
rotate([0,0,j*360/3])
	for(i = [-1,1])
	translate([i*5 ,18,4])
	traxxis_ball();

for(j = [0:2])
rotate([0,0,j*360/3])
translate([0 ,13,5])
dodgy_standoffs();


translate([0 ,0,40]){
top_end_open();
top_end_closed();
}
translate([0 ,0, 45])
top_tube_fix();

}



module traxxis_ball(){
color("silver"){
sphere(r=3);
}
}




module dodgy_standoffs(){
color("silver"){

cylinder(r=1.6,h=35);


}
}


translate([0,0,-10])
extruder();
platform_assembled();

