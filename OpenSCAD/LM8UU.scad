module hex(s,d=14){


linear_extrude(s)
hull(){
for(i = [0:5])
rotate([0,0,i*360/6])
translate([d/2,0,0]) 
circle([1,1]);
}

}




module LM8UU(){
h = 24;
d = 15/2;
inner = 8/2; //m8
offset = 4;

difference(){
ring(h,"silver",d,d-1);

for(i = [offset,h-offset-1]) //why the -1?
translate([0,0,i]) ring(1,"silver",d+1,d-.5);

}


ring(h,"black",d-1,inner);








}




module ring(height,colour,outer,inner){

color(colour){
difference(){
cylinder(r=outer,h=height);

translate([0,0,-.5]) cylinder(r=inner,h=height+1);

}
}
}



