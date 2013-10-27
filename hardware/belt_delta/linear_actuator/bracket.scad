$fn = 40;

module fillet(r, h) {
    translate([r / 2, r / 2, 0])

        difference() {
            cube([r + 0.01, r + 0.01, h], center = true);

            translate([r/2, r/2, 0])
                cylinder(r = r, h = h + 1, center = true);

        }
}


module fillet_face(r,h,s,x){


//front
for(i = [0,1]){
translate([0,0,i*s])
rotate([0,i*90,0])
translate([0,s,s/2]) {
rotate([180,0,0])		fillet(r,s);
translate ([s,0,0]) rotate([180,180,0])		fillet(r,s);
}
}



//sides
translate([0,0,0])
for(i = [0,1]){
	translate([0,0,i*s])
	rotate([i*180,0,0])
	union(){
	rotate([90,0,0])		fillet(r,x);
	 translate([s,0,0]) rotate([90,0,180])		fillet(r,x);
	}
}

union(){
for(i = [0,1]){

rotate([0,i*180,0])
translate([-i*s,0,-i*s]){

translate([s-r,s-r,s-r]){
	difference(){
	cube([r,r,r]);
	sphere(r);
	}
}

translate([s-r,s-r,r]){
	rotate([0,90,0])
	difference(){
	cube([r,r,r]);
	sphere(r);
	}


}

}

}
	}
	
}



module bracket_bottom(){

	outer = 42;
	inner = 31/2;
	len = 0;
	plate_height = 16;
	outset = 26;

	depth=6;

color("white"){

for(i=[0,1])
mirror([i,0,0])
difference(){
union(){
	translate([10,0,0]) cube([outer,outer,5],center=true);
	//cube([outer+24,outer,5],center=true);
		translate([17,0,depth-2])cube([14,outer,10],center=true);
		translate([36,0,depth-9.6])rotate([0,60,0]){
		cube([25,outer,10],center=true);
	
	translate([-3,0,12])	
		difference(){
		cube([10,outer,14],center=true);
		for(j = [-1,1])
		rotate([0,90,0]){
		translate([0,j*13,-10])
		cylinder(r=4,h=25);

		if(j == -1)
		translate([-7,j*outer/2,0]) rotate([0,0,0]) fillet(8,25);
		else
		translate([-7,j*outer/2,0]) rotate([180,0,0]) fillet(8,25);

		}

		}

		}

		translate([27,0,depth])rotate([90,0,0])cylinder(r=8,h=outer,center=true);




}
	translate([24,0,depth-1])cube([2,outer+2,2],center=true);
	translate([16,0,depth-2.5])cube([25,outer+2,2],center=true);
	translate([27,0,depth])rotate([90,0,0])cylinder(r=4,h=outer+2,center=true);
	for(i = [0:4])
	rotate(i*360/4)
	translate([inner,inner,0])	cylinder(r=1.7, h=30,center=true);
	cylinder(r=15, h=30,center=true);
	translate([0,0,-depth-4])cube([outer+80,outer+2,15],center=true);

}
//		for(i = [-1,1])		


}
}




module bracket_top(){

	outer = 42;
	inner = 31/2;
	len = 0;
	plate_height = 16;
	outset = 26;

	depth=6;

color("white"){
difference(){

for(i=[0,1])
mirror([i,0,0])
difference(){
union(){
	translate([10,0,0]) cube([outer,outer,5],center=true);



	translate([0,0,-4])
	difference(){
		cylinder(r=15,h=26);
		cylinder(r=11.05,h=68,center=true);
	}

		difference(){
		translate([17,0,depth-2])cube([14,outer,10],center=true);
		translate([0,0,5.5]) cylinder(r=17, h=8,center=true);
		}
		translate([36,0,depth-9.6])rotate([0,60,0]){
		cube([25,outer,10],center=true);
	
	translate([-3,0,12])	
		difference(){
		cube([10,outer,14],center=true);
		for(j = [-1,1])
		rotate([0,90,0]){
		translate([0,j*13,-10])
		cylinder(r=4,h=25);

		if(j == -1)
		translate([-7,j*outer/2,0]) rotate([0,0,0]) fillet(8,25);
		else
		translate([-7,j*outer/2,0]) rotate([180,0,0]) fillet(8,25);

		}

		}

		}

		translate([27,0,depth])rotate([90,0,0])cylinder(r=8,h=outer,center=true);




}
	union(){
	translate([24,0,depth-1])cube([2,outer+2,2],center=true);
	translate([16,0,depth-2.5])cube([25,outer+2,2],center=true);
	translate([27,0,depth])rotate([90,0,0])cylinder(r=4,h=outer+2,center=true);
	for(i = [0:4])
	rotate(i*360/4)
	translate([inner,inner,0])	cylinder(r=1.7, h=30,center=true);
	cylinder(r=11.05, h=30,center=true);
	translate([40,0,-depth-4])cube([outer,outer+2,15],center=true);

	}

}
//		for(i = [-1,1])		



//#		translate([-14,2,2.5]) cube([28,10,13]);
	translate([0,0,2.5])
	difference(){
		cylinder(r=17,h=12);
	translate([-20,0,0])	cube(40,30,20);
//		cylinder(r=11,h=68,center=true);
	}
}}
}



bracket_top();
//bracket_bottom();
