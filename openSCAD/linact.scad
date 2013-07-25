$fn = 100;

module end_piece(){
width = 20;
radius = 6;
height = 2;



difference(){
union(){

cylinder(r = radius, h = height, center = true);
translate([-radius,0,0])	cube([20,radius/2,height], center = true);
}

cylinder(r = 4, h = height+1, center = true);

}


}



end_piece();