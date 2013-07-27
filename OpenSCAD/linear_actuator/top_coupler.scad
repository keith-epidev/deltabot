include <nema.scad>
include <LM8UU.scad>

$fn = 50;

module plate(){
outer = 42/2;
inner = 31/2;
len = 0;
plate_height = 6;
outset = 26;

union(){

difference(){
union(){
color("white") cylinder(r=(22.5+4)/2,h=plate_height);
translate([-outset+8,-6,0])
color("white") cube([(outset-8)*2,12,plate_height]);
}

color("white") cylinder(r=22.5/2,h=5,center = true);

color("white") cylinder(r=12/2,h=18,center = true);
}


for(i = [0,180]){

rotate([0,0,i])
translate([outset,0,0])
difference(){
union(){
color("white") cylinder(r=6,h=len+plate_height);
color("white") translate([-8,-6,0]) cube([18,6*2,plate_height]);
}
translate([0,0,-1]) color("white") cylinder(r=4.2,h=len+plate_height+2);

color("white") translate([3,-1,-1]) cube([8,2,plate_height+2]);

color("white") 
translate([7,7,3]){ 
rotate([90,0,0]){
hex(s=2,d=3);
cylinder(r=1.5, h=14);

}

}



}

}



}

}


plate();