$fn = 30;

module nema_plane(outer,inner,height,bore,colour){

side = inner + 1;
diff = (outer - side);


difference(){

color(colour)
for(i = [0:4])
rotate(i*360/4){
	difference(){
		linear_extrude(height)
			polygon([ [-1,-1], [outer,-1], [outer,side], [outer-diff,side+diff], [-1,outer] ]);

		translate([inner,inner,0])
			cylinder(r=bore, h=height*2+1,center=true);
	}
}

color(colour)
cylinder(r=4, h=height*2+1,center=true);
}

}


module bottom(){
outer = 42/2;
inner = 31/2;

nema_plane(outer,inner,8.7,3,"silver");
}



module middle(){
outer = 42/2;
inner = 28/2;

nema_plane(outer,inner,30,1.5,"black");

}


module top(){ 
outer = 42/2;  
inner = 31/2;  

difference(){

union(){
nema_plane(outer,inner,7.8,1.5,"silver");

color("silver")
translate([0,0,4])
cylinder(r=11, h=1);
}
color("silver")
cylinder(r=4, h=20,center = true);

}

}


module axle(){

color("silver")
cylinder(r=2.5, h=24+8+30);

}

module nema17(){
translate([0,0,-(30+8.7+7.8)]){
	translate([0,0,0]) bottom();
	translate([0,0,30+8.7]) top();
	translate([0,0,8.7]) middle();
	translate([0,0,0]) axle();
}
}



