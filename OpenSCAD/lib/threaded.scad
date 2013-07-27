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
color("white") cylinder(r=7.5,h=5);


translate([0,0,0])
color("white") cylinder(r=2.6,h=26);

translate([0,0,16])
rotate([90,0,0])
color("white") cylinder(r=1.5,h=16);


translate([-1,-1,3])
color("white") cube([12,18,5]);


}

}




coupler();
