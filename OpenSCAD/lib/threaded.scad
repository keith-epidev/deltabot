$fn = 50;

module threaded(h=1000,r=4){
color("silver")
cylinder(r=r,h=h);
}

module coupler(){

difference(){
color("white") cylinder(r=10,h=20);

translate([0,0,-1])
color("white") cylinder(r=4,h=9);

translate([0,0,3])
color("white") cylinder(r=7.5,h=7);


translate([0,0,0])
color("white") cylinder(r=2.6,h=26);

translate([0,0,16])
rotate([90,0,0])
color("white") cylinder(r=1.5,h=16);


translate([-2,-4,3])
color("white") cube([12,18,7]);


}

}




module coupler_5mm(){

difference(){
color("white") cylinder(r=6,h=15);

translate([0,0,-1])
color("white") cylinder(r=2.5,h=9);

translate([0,0,3])
color("white") cylinder(r=9/2,h=7);


translate([0,0,0])
color("white") cylinder(r=2.6,h=26);

translate([0,0,12])
rotate([90,0,0])
color("white") cylinder(r=1.5,h=16);


translate([-2,-4,3])
color("white") cube([12,18,4]);


}

}




coupler_5mm();
