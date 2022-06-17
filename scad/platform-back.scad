$fn = 50;

module step1()
{
    union()
    {
        translate([-70, 0, 0])
            cube([140, 140, 3]);
        translate([0, 27.5, 0])
            cylinder(3, 132.5, 132.5);
    }
}

module step2()
{
    difference()
    {
        step1();
        mirror([1, 0, 0])
        translate([-132.5, -100, 0])
            cube([62.5, 300, 3]);
        translate([-132.5, -100, 0])
            cube([62.5, 300, 3]);
        translate([-132.5, -120, 0])
            cube([265, 120, 3]);
    }
}

module step3()
{
    difference()
    {
        step2();
        mirror([1, 0, 0])
        {
            // Gearbox
            translate([-70, 80, 2])
                cube([18.8, 48.2, 1.5]);
            // Motor
            translate([-70, 63, 1.5])
                cube([18.8, 17, 2]);
        }
        {
            // Gearbox
            translate([-70, 80, 2])
                cube([18.8, 48.2, 1.5]);
            // Motor
            translate([-70, 63, 1.5])
                cube([18.8, 17, 2]);
        }
    }
}

module step4()
{
    union()
    {
        step3();
        mirror([1, 0, 0])
        difference()
        {
            translate([-62.1, 128.2, 3])
            {
                hull()
                {
                    cube([20, 6, 2]);
                    translate([0, 0, 7.72])
                        cube([16, 6, 2]);
                }
            }
            translate([-62.1, 128.2, 7.72])
                cube([2.8, 5, 5]);
            translate([-62.1, 130.7, 10.22])
                rotate([0, 90, 0])
                    cylinder(20, 1.25, 1.25);
        }
        difference()
        {
            translate([-62.1, 128.2, 3])
            {
                hull()
                {
                    cube([20, 6, 2]);
                    translate([0, 0, 7.72])
                        cube([16, 6, 2]);
                }
            }
            translate([-62.1, 128.2, 7.72])
                cube([2.8, 5, 5]);
            translate([-62.1, 130.7, 10.22])
                rotate([0, 90, 0])
                    cylinder(20, 1.25, 1.25);
        }
        mirror([1, 0, 0])
        difference()
        {
            translate([-51.2, 93, 3])
            {
                hull()
                {
                    cube([7, 35.2, 2]);
                    translate([0, 0, 7.72])
                    {
                        cube([3, 35.2, 2]);
                    }
                }
            }
            translate([-51.2, 96.85, 4.42])
                rotate([0, 90, 0])
                    cylinder(4, 1.25, 1.25);
        }
        difference()
        {
            translate([-51.2, 93, 3])
            {
                hull()
                {
                    cube([7, 35.2, 2]);
                    translate([0, 0, 7.72])
                    {
                        cube([3, 35.2, 2]);
                    }
                }
            }
            translate([-51.2, 96.85, 4.42])
                rotate([0, 90, 0])
                    cylinder(4, 1.25, 1.25);
        }
    }
}

step4();