include <shapes.scad>;



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


