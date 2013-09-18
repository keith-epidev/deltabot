module bracket(){


len = 0;
plate_height = 12;
outset = 26;



difference(){
union(){
color("white") cylinder(r=6,h=len+plate_height);
color("white") translate([-7,-6,0]) cube([23,6*2,plate_height]);
}
translate([0,0,-1]) color("white") cylinder(r=4.2,h=len+plate_height+2);
color("white") translate([3,-1,-1]) cube([20,2,plate_height+2]);

color("white")
translate([9,7,plate_height/2])
rotate([90,0,0]) cylinder(r=4.2,h=len+plate_height+4);



}



}

bracket();
