/*
 * trainer_gpio.c
 *
 * Initial code: Denny (Dongsung) Yang
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/stat.h>
#include <linux/gpio.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Denny Dongsung Yang");

static short int myshort = 1;
static int myint = 420;
static long int mylong = 9999;
static char *mystring = "blah";
static int myintArray[2] = { -1, -1 };
static int arr_argc = 0;

/* 
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits, 
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");
module_param(mystring, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

/*
 * module_param_array(name, type, num, perm);
 * The first param is the parameter's (in this case the array's) name
 * The second param is the data type of the elements of the array
 * The third argument is a pointer to the variable that will store the number 
 * of elements of the array initialized by the user at module loading time
 * The fourth argument is the permission bits
 */
module_param_array(myintArray, int, &arr_argc, 0000);
MODULE_PARM_DESC(myintArray, "An array of integers");

static int __init trainer_gpio_init(void)
{
        printk(KERN_INFO "Beagle expansionboard: exporting GPIOs 130-141,162 to userspace\n");
        gpio_request(130, "sysfs");
        gpio_export(130, 1);
        gpio_request(131, "sysfs");
        gpio_export(131, 1);
        gpio_request(132, "sysfs");
        gpio_export(132, 1);
        gpio_request(133, "sysfs");
        gpio_export(133, 1);
        gpio_request(134, "sysfs");
        gpio_export(134, 1);
        gpio_request(135, "sysfs");
        gpio_export(135, 1);
        gpio_request(136, "sysfs");
        gpio_export(136, 1);
        gpio_request(137, "sysfs");
        gpio_export(137, 1);
        gpio_request(138, "sysfs");
        gpio_export(138, 1);
        gpio_request(139, "sysfs");
        gpio_export(139, 1);
        gpio_request(140, "sysfs");
        gpio_export(140, 1);
        gpio_request(141, "sysfs");
        gpio_export(141, 1);
        gpio_request(162, "sysfs");
        gpio_export(162, 1);

	return 0;
}

static void __exit trainer_gpio_exit(void)
{
	printk(KERN_INFO "Exit of trainer_gpio\n");
}

module_init(trainer_gpio_init);
module_exit(trainer_gpio_exit);

