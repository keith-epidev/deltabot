include <../lib/nema.scad>;
include <../lib/LM8UU.scad>;
include <../hardware/extruder.scad>;


//mirror([0,0,1])
//reel_holder();
module reel_holder(){
		difference(){
			union(){
			strut();


			translate([0,28,0])
			rotate([0,30,0])
			difference(){
			union(){
			cylinder(r=8,h=14,center=true);
			rotate([0,-30,0])
			translate([0,-8,0])
			cube([10,16,14],center=true);
			}
			
			cylinder(r=4.5,h=64,center=true);


			}

			}
			translate([0,13,0])
		rotate([0,90,0])
			cylinder(r=4.5,h=64,center=true);

			
	}





}




module top_box(){
	color("white")
	difference(){
		cube([37,56,6]);

	translate([18,25,-20])
		cylinder(r=4,h=30);

	translate([7,50,-20])
		cylinder(r=1.7,h=30);

	translate([32,6,-20])
		cylinder(r=1.7,h=30);


	translate([14,6,1])
		cube([8,3,10]);

	translate([18,8,3])
		rotate([90,0,0])
		cylinder(r=1.6,h=30);





	}

}


translate([-18,-25,37])
top_box();


module nema_couple(){
	outer = 42/2;  
	inner = 31/2;  

color("white")
difference(){
union(){
	translate([30,0,3])
		rotate([0,90,0])
	union(){
			strut();
		translate([-5,-17,-10])
		cube([8,34,5]);
	}


	translate([-26,-16,-16])
difference(){
	cube([5,40,24]);

translate([0,35,-10])
	cylinder(r=1.5,h=16);
}

	translate([-61,-16,0]){
difference(){
	cube([42,32,8]);
translate([21,16,-40])
	cylinder(r=4,h=80);
}

	translate([16,-15,-16])

	difference(){
	cube([10,15,24]);
	translate([5,55,12])
	rotate([90,0,0])
	cylinder(r=2,h=400);
	}


	translate([4,-15,0])




	difference(){
	cube([12,18,8]);
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


translate([0,6,6])
rotate([0,90,0])
cylinder(r=1.5,h=16);

translate([14,4,4])
cube([3,8,16]);

	translate([35,5,-20])
		cylinder(r=1.5,h=25);


translate([0,6,18])
rotate([0,90,0])
cylinder(r=1.5,h=16);

	translate([21,13,12])
		rotate([90,0,0])
			cylinder(r1=1,r2=4,h=14);

	//tube fix mount  bolts
	translate([32,16,16.5])
		rotate([90,0,0])
			cylinder(r=1.5,h=24);


	}
	}


	}	
difference(){
	nema_plane(outer,inner,8,1.5,"white");
//bores

for(i = [0:4])
rotate(i*360/4)
		translate([inner,inner,6])
			cylinder(r=3.2, h=5,center=true);
}


}



translate([-71,-20,-20])
	cube([20,60,40]);
translate([-56,0,-20])
cylinder(r=10,h=40);
translate([0,0,-2])
	cylinder(r=17,h=42,center=true);
	}




}
		//	nema_couple();
	//top_tube_fix();

translate([40,0,21]){
	rotate([180,0,0]){
		nema17();

		translate([0,0,0])
			nema_couple();
	}

	translate([27,0,-3])
		rotate([0,90,0])
			strut();
}


translate([0,-25,27])
	rotate([90,-0,0])
	top_tube_fix();


//			nema_couple();



translate([0,0,11])
R608zz();

translate([0,0,37])
R608zz();

translate([0,45,27])
rotate([90,90,0])
plastic();

big_gear();
little_gear();
drive_shaft();


translate([-11,-25,37])
rotate([270,0,90])
arm();




module plastic(){
color("green")
cylinder(r=1.7/2,h=180);
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
l = 24;

/*
translate([w/2,7/2+12,0])
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

//translate([w/2-10,0,-10])
//	cube([10*2,l,10]);

	//hinge
	translate([w,0,0])
		rotate([270,0,0])
			cylinder(r=6,h=l);
}


translate([44,16,-6])
cube([14,14,14]);

//axle
translate([w/2,l,0])
	rotate([90,0,0])
		cylinder(r=4.2,h=l*3,center=true);
translate([w/2-12,l/2-4.1,-11])
	cube([24,8.2,21]);

//hinge
translate([w,0,0])
	rotate([270,0,0])
		cylinder(r=1.7,h=l*3,center=true);


translate([5,6,0])
	rotate([0,0,90])
	cylinder(r=2,h=42,center=true);

translate([5,l-6,0])
	rotate([0,0,90])
	cylinder(r=2,h=42,center=true);



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




