include <../lib/nema.scad>;
include <../lib/LM8UU.scad>;
include <../hardware/extruder.scad>;

module nema_couple(){
	outer = 42/2;  
	inner = 31/2;  

color("white")
difference(){
union(){

	translate([27,0,3])
		rotate([0,90,0])
			strut();

	translate([-26,-16,-16])
	cube([5,40,24]);
	translate([-61,-16,0]){
	cube([42,32,8]);
	translate([0,-15,0])

	difference(){
	cube([12,32,8]);
	translate([6,6,-10])
		cylinder(r=1.8,h=20);

	translate([6,6,5])
		cylinder(r=3,h=4);
	}
		

	translate([0,30,-16]){
	difference(){
	cube([36,10,24]);
translate([-1,-2,-1])
	cube([6,20,17]);

translate([0,6,5])
rotate([0,90,0])
cylinder(r=1.5,h=10);

translate([8,4,2])
cube([3,8,12]);

translate([0,6,11])
rotate([0,90,0])
cylinder(r=1.5,h=10);

	translate([17,13,10])
		rotate([90,0,0])
			cylinder(r1=1,r2=4,h=14);

	translate([30,13,10])
		rotate([90,0,0])
			cylinder(r=1.5,h=14);

	}
	}


	}	

	nema_plane(outer,inner,8,1.5,"white");
}

	cylinder(r=14,h=20,center=true);
	}


}

arm();

/*

translate([40,0,21]){
	rotate([180,0,0]){
		nema17();

		translate([0,0,0])
	}

	translate([27,0,-3])
		rotate([0,90,0])
			strut();
}




translate([-4,-25,27])
	rotate([90,-30,0])
	top_tube_fix();


translate([-4,45,27])
rotate([90,90,0])
plastic();

big_gear();
little_gear();
drive_shaft();


translate([-15,-25,37])
rotate([270,0,90])
arm();




*/


module plastic(){
color("green")
cylinder(r=1.7/2,h=80);
}



module drive_shaft(){

color("silver")
difference(){
cylinder(r=4,h=55);

	translate([0,0,25])
	difference(){
		cylinder(r=5,h=5);
		cylinder(r=3,h=5);
	}
}
}



module big_gear(){
translate([0,0,10])
rotate([0,180,0])
import("herringbone-gear-large.stl");
}



module little_gear(){
translate([40,0,0])
 translate([15,0,0]) import("herringbone-gear-small.stl");
}




module arm(){
w = 50;
l = 16;
/*
translate([w/2,7/2+10,0])
rotate([90,0,0])
R608zz();
*/

difference(){
union(){
	cube([w,l,6]);

//axle
translate([w/2,l,0])
	rotate([90,0,0])
		cylinder(r=8,h=l);

translate([w/2-10,0,-10])
	cube([10*2,l,10]);

	//hinge
	translate([w,0,0])
		rotate([270,0,0])
			cylinder(r=6,h=l);
}
//axle
translate([w/2,l,0])
	rotate([90,0,0])
		cylinder(r=4.2,h=l*3,center=true);
translate([w/2-11,l/2-4.1,-11])
	cube([22,8.2,21]);

//hinge
translate([w,0,0])
	rotate([270,0,0])
		cylinder(r=1.7,h=l*3,center=true);


translate([5,5,0])
	rotate([0,0,90])
	cylinder(r=1.8,h=42,center=true);

translate([5,l-5,0])
	rotate([0,0,90])
	cylinder(r=1.8,h=42,center=true);



}
}








module fillet(r, h) {
    translate([r / 2, r / 2, 0])

        difference() {
            cube([r + 0.01, r + 0.01, h], center = true);

            translate([r/2, r/2, 0])
                cylinder(r = r, h = h + 1, center = true);

        }
}


module strut(){

	outer = 42;
	inner = 31/2;
	len = 0;
	plate_height = 16;
	outset = 26;

	depth=6;

color("white"){


		difference(){
		union(){
		cube([10,outer-15,14],center=true);
		translate([-5,13,0])
		rotate([0,90,0])
		cylinder(r=7,h=10);
		translate([-5,-13,0])
		rotate([0,90,0])
		cylinder(r=7,h=10);
		}


		for(j = [-1,1])
		rotate([0,90,0]){
		translate([0,j*13,-10])
		cylinder(r=4.2,h=25);
/*
		if(j == -1)
		translate([-7,j*outer/2,0]) rotate([0,0,0]) fillet(8,25);
		else
		translate([-7,j*outer/2,0]) rotate([180,0,0]) fillet(8,25);
*/

		}

		}

}

}




