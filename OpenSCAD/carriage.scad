include <LM8UU.scad>

carriage();
$fn = 10;

module carriage_section(){
sheeth_h = 6;
h = 28/2;

color("white"){


difference(){
union(){
for(i = [0,180]){

rotate([0,0,i])

translate([16,0,0])
difference(){
union(){
cylinder(r=15/2+2,h=sheeth_h);

rotate([0,0,90]) translate([-6,6,0])	cube([10,20,h]);

}

translate([0,0,2]) cylinder(r=15/2,h=sheeth_h+1);
translate([0,0,-1]) cylinder(r=9/2,h=sheeth_h*2+1);


}



}

}

translate([0,0,-.5]) cylinder(r=9/2,h=h+1);
translate([0,0,h-2.5]) rotate([0,0,0]) hex(3.5);

for(i = [0,180])
rotate([0,0,i])
translate([16,0,2]) cylinder(r=15/2,h=sheeth_h*2+1);



//drill some mount holes
for(i = [-6,6])
translate([i,15,h/2])
rotate([90,0,0])	cylinder(r=1.3,25);


//drill some assembly holes
for(i = [-7,7])
translate([i,0,-.5])
rotate([0,0,0])	cylinder(r=1.3,25);


}






}





}


module carriage(){

carriage_section();


translate([0,0,28])
rotate([180,0,0])
carriage_section();



for(i = [-16,16])
translate([i,0,2])
LM8UU();







}



