$fn = 50;

union()
{
    difference()
    {
        difference()
        {
            union()
            {
                translate([ -70, 0, 0 ])
                    cube([ 140, 140, 3 ]);
                translate([ 0, 27.5, 0 ])
                    cylinder(3, 132.5, 132.5);
            }
            mirror([ 1, 0, 0 ])
                translate([ -132.5, -100, 0 ])
                    cube([ 62.5, 300, 3 ]);
            translate([ -132.5, -100, 0 ])
                cube([ 62.5, 300, 3 ]);
            translate([ -132.5, -120, 0 ])
                cube([ 265, 120, 3 ]);
        }
        mirror([ 1, 0, 0 ])
        {
            // Gearbox
            translate([ -70, 80, 2 ])
                cube([ 18.8, 48.2, 1.5 ]);
            // Motor
            translate([ -70, 63, 1.5 ])
                cube([ 18.8, 17, 2 ]);
        }
        {
            // Gearbox
            translate([ -70, 80, 2 ])
                cube([ 18.8, 48.2, 1.5 ]);
            // Motor
            translate([ -70, 63, 1.5 ])
                cube([ 18.8, 17, 2 ]);
        }
    }
    mirror([ 1, 0, 0 ])
        difference()
        {
            translate([ -62.1, 128.2, 3 ])
            {
                hull()
                {
                    cube([ 20, 6, 2 ]);
                    translate([ 0, 0, 7.72 ])
                        cube([ 16, 6, 2 ]);
                }
            }
            translate([ -62.1, 128.2, 7.72 ])
                cube([ 2.8, 5, 5 ]);
            translate([ -62.1, 130.7, 10.22 ])
                rotate([ 0, 90, 0 ])
                    cylinder(20, 1.25, 1.25);
        }
    difference()
    {
        translate([ -62.1, 128.2, 3 ])
        {
            hull()
            {
                cube([ 20, 6, 2 ]);
                translate([ 0, 0, 7.72 ])
                    cube([ 16, 6, 2 ]);
            }
        }
        translate([ -62.1, 128.2, 7.72 ])
            cube([ 2.8, 5, 5 ]);
        translate([ -62.1, 130.7, 10.22 ])
            rotate([ 0, 90, 0 ])
                cylinder(20, 1.25, 1.25);
    }
    mirror([ 1, 0, 0 ])
        difference()
        {
            translate([ -51.2, 93, 3 ])
            {
                hull()
                {
                    cube([ 7, 35.2, 2 ]);
                    translate([ 0, 0, 7.72 ])
                        cube([ 3, 35.2, 2 ]);
                }
            }
            translate([ -51.2, 96.85, 4.42 ])
                rotate([ 0, 90, 0 ])
                    cylinder(4, 1.25, 1.25);
            translate([ -51.2, 116.7, 10.22 ])
            {
                rotate([ 0, 90, 0 ])
                    cylinder(20, 2.75, 2.75);
                translate([0, -2.75, 0])
                    cube([20, 5.5, 5]);
            }
            translate([-51.2, 105.45, 10.22])
            {
                rotate([0, 90, 0])
                    cylinder(3, 2.05, 2.05);
            }
        }
    difference()
    {
        translate([ -51.2, 93, 3 ])
        {
            hull()
            {
                cube([ 7, 35.2, 2 ]);
                translate([ 0, 0, 7.72 ])
                    cube([ 3, 35.2, 2 ]);
            }
        }
        translate([ -51.2, 96.85, 4.42 ])
            rotate([ 0, 90, 0 ])
                cylinder(4, 1.25, 1.25);
        translate([ -51.2, 116.7, 10.22 ])
        {
            rotate([ 0, 90, 0 ])
                cylinder(20, 2.75, 2.75);
            translate([0, -2.75, 0])
                cube([20, 5.5, 5]);
        }
        translate([-51.2, 105.45, 10.22])
        {
            rotate([0, 90, 0])
                cylinder(3, 2.05, 2.05);
        }
    }
    difference()
    {
        hull()
        {
            difference()
            {
                translate([0, 24.5, 3])
                    cylinder(9.72, 132.5, 132.5);
                translate([0, 24.5, 3])
                    cylinder(9.72, 130, 130);
                mirror([ 1, 0, 0 ])
                    translate([ -132.5, -100, 3 ])
                        cube([ 62.5, 300, 9.72 ]);
                translate([ -132.5, -100, 3 ])
                    cube([ 62.5, 300, 9.72 ]);
                translate([ -132.5, -120, 3 ])
                    cube([ 265, 120, 9.72 ]);
            }
            translate([-70, 134, 3])
                cube([140, 1, 9.72]);
        }
        difference()
        {
            translate([0, 34, 3])
                cylinder(9.72, 120, 120);
            mirror([1, 0, 0])
                translate([-70, 0, 3])
                    cube([29, 160, 9.72]);
            translate([-70, 0, 3])
                cube([29, 160, 9.72]);
        }
    }
    difference()
    {
        translate([-20, 70, 3])
            cube([40, 77, 9.72]);
        mirror([1, 0, 0])
        {
            translate([-10, 70, 3])
                cylinder(9.72, 1.25, 1.25);
            translate([-10, 147, 3])
                cylinder(9.72, 1.25, 1.25);
            translate([-10, 81, 6.72])
                cylinder(6, 1.1, 1.1);
            translate([-10, 136, 6.72])
                cylinder(6, 1.1, 1.1);
        }
        translate([-10, 70, 3])
            cylinder(9.72, 1.25, 1.25);
        translate([-10, 147, 3])
            cylinder(9.72, 1.25, 1.25);
        translate([-10, 81, 6.72])
            cylinder(6, 1.1, 1.1);
        translate([-10, 136, 6.72])
            cylinder(6, 1.1, 1.1);
        translate([0, 70, 12.72])
            rotate([-90, 0, 0])
                cylinder(77, 4, 4);
        translate([-18, 103, 9.72])
            cube([16, 11, 3]);
    }
    translate([-15, 111, 9.72])
        cylinder(1.5, 1.6, 1.6);
}
