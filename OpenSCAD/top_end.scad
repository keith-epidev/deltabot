$fn = 50;


module top_end(){
outer = 42/2;
inner = 31/2;
len = 20;


difference(){
union(){


color("white") cylinder(r=13,h=7);



translate([-16,-5,0])
color("white")
cube([32,10,7]);



for(i = [16,-16]){

translate([i,0,0])
difference(){
color("white") cylinder(r=5,h=len+4);

translate([0,0,2]) color("white") cylinder(r=4,h=len+4);
}

}




translate([16,0,5])
rotate([60,90,0])
difference(){
color("white") cylinder(r=5,h=len);
translate([0,0,2]) color("white") cylinder(r=4,h=len);
}


translate([16,0,5])
rotate([30,0,30])
difference(){
color("white") cylinder(r=5,h=len);
translate([0,0,2]) color("white") cylinder(r=2,h=len);
}





translate([-16,0,5])
rotate([60,-90,0])
difference(){
color("white") cylinder(r=5,h=len);
translate([0,0,2]) color("white") cylinder(r=4,h=len);
}


translate([-16,0,5])
rotate([30,0,-30])
difference(){
color("white") cylinder(r=5,h=len);
translate([0,0,2]) color("white") cylinder(r=2,h=len);
}

}

union(){
translate([0,0,2])
color("white") cylinder(r=11.5,h=5.01);

translate([0,0,-2])
color("white") cylinder(r=7,h=5.0);

}


}


}

