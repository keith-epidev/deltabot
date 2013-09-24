$fn = 30;

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
		rotate([0,0,60]){
		difference(){
		rotate([0,90,0]) cylinder(r=9,h=14,center=true);
//		cube([15,13,13],center=true);
		rotate([0,90,0])
		cylinder(r=4.4,h=28,center=true);

		}
	
	}


	translate([0,0,15])	
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






mirror([0,1,0])
strut();
