include <LM8UU.scad>



$fn = 50;

module carriage(){

outer = 42/2;
inner = 31/2;
len = 0;
plate_height = 8;
outset = 26;


d = 15+1;
r = d/2;
test = outset - r;

union(){

difference(){
translate([-test,-(d+4)/2,0]) color("white") cube([test*2,20,plate_height]);
translate([0,0,-1])
hex(s=plate_height+2,d=14.7);

for(i = [-13,13])
translate([i,0,-1])
cylinder(r=1.5, h=plate_height+2);

for(i = [-13,13])
translate([i,d,plate_height/2])
rotate([90,0,0])
cylinder(r=1.5, h=40);

translate([0,d,plate_height/2])
rotate([90,0,0])
cylinder(r=1.5, h=40);

}

for(i = [0,180]){

rotate([0,0,i])
translate([outset,0,0])
difference(){
union(){
color("white") cylinder(r=6,h=len+plate_height);
color("white") translate([-9,-r-2,0]) cube([24,d+4,plate_height]);
}
translate([0,0,-1]) color("white") cylinder(r=r,h=len+plate_height+2);

color("white") translate([3,-1,-1]) cube([14,2,plate_height+2]);

color("white") 
translate([r+4,r+3,4]){ 
rotate([90,0,0]){
hex(s=2,d=3);
cylinder(r=1.5, h=d+10);

}

}

}

}



}
}


carriage();