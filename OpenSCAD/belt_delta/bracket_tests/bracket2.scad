include <lib/nema.scad>;


$fn = 30;
height = 330;
width = height /2;

outer = 42/2;
inner = 31/2;
len = 0;
plate_height = 16;
outset = 26;

module mount(){

color("white") {
	difference(){
	union(){
	cube([outer*2,5,plate_height]);
	rotate([0,90,0])
	translate([-8,5,0]){
		cylinder(r=8,h=outer*2);
		translate([-4,4,0])cube([10,8,outer*2]);
	}
	}
	rotate([0,90,0]) translate([-8,5,-1]) cylinder(r=4,h=outer*2+3);
	translate([-10,6,5]) cube([105,14,5]);
	


	for(i = [0,18,36]){
		translate([3+i,14,0]) cylinder(r=1.3, h=20);
	}

	}

}


}


module bracket(){

color("white"){
for(z = [0,180])
rotate(z,0,0){
	translate([-outer,outer+16,0])
		difference(){

			union(){

			translate([0,-3,6]) rotate([90,0, 0]) mount();

			 rotate([30,0,0]) translate([0,0,3]) cube([outer*2,3,10]);
			
			translate([0,-2,3.2]) rotate([0,90,0]) cylinder(r=3.2, h=outer*2);
			translate([0,-22,0]) cube([outer*2,20,6]);
		}
			for(i = [0,18,36])
			rotate([30,0,0]) translate([3+i,10,7]) rotate([90,0,0]) cylinder(r=1.1, h=16);

	translate([-1,-3.5,3.5]) rotate([0,90,0]) cylinder(r=1.1,h=outer*2+2);
	

}

}

#

difference(){
	nema_plane(outer,inner,6,1.5,"white");
	color("white") {
		cylinder(r=15,h=plate_height*2+1,center = true);
		translate([0,-10,-1]) rotate([0,0,90])  cube([20,30,25]);
	}
}




}

}



bracket();
//nema17();
