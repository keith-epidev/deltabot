include <lib/LM8UU.scad>;
include <extruder.scad>

module carriage_clamp(){
color("white"){
difference(){
union(){
cube([8,16,4]);
translate([4,0,0]){
	cylinder(r=4,h=4);
	translate([0,12,0]) cylinder(r=4,h=4);
}
}

translate([4,0,-1]){
	cylinder(r=1.7,h=7);
	translate([0,12,0]) cylinder(r=1.7,h=7);
}

}}
}

module carriage(){
color("white"){

difference(){
union(){
difference(){
for(i = [0,1])
mirror([i,0,0]){
difference(){
translate([0,-10,0]) cube([45,20,8]);
translate([27,0,-1]) cylinder(r=15/2,h=20);
translate([27,-4,-1]) cube([20,8,20]);


}


//bearing
//translate([27,0,0]){LM8UU();}
}

translate([4,-7,-1]) cube([12,14,20]);
translate([-3,-3,-1]) cube([8,6,20]);
translate([-10,-3,-1]) cube([4,6,20]);
}
translate([0,4,0]) 
difference(){
traxxis_mount();
translate([0,-1,-1]) cube([20,5,12]);
}
}

for(i = [0,1])
mirror([i,0,0]){
translate([-41,20,4]) rotate([90,0,0]) cylinder(r=1.5,h=40);
translate([-41,14,4]) rotate([90,0,0]) cylinder(r=3,h=3);
translate([-41,-11,4]) rotate([90,0,0]) cylinder(r=3,h=3);
}

for(i = [0,1])
mirror([0,i,0]){
translate([-8,6,-1]){ rotate([0,0,0]) cylinder(r=1.7,h=10);

hex(s=4,d=6);
}
}
//end stop pole
translate([0,8,-1]){ rotate([0,0,0]) cylinder(r=1.5,h=10);

}

}

}}


carriage();

//translate([-12,-8,8]) carriage_clamp();
