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

static int debug = 0;

/* 
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits, 
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */

module_param(debug, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(debug, "debug");

static int __init trainer_gpio_init(void)
{
        printk(KERN_INFO "Beagle expansionboard: exporting GPIOs 130-141,162 to userspace\n");
        gpio_request(130, "sysfs");
        gpio_export(130, 1);
        gpio_request(131, "sysfs");
        gpio_export(131, 1);
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

	/* Trainer GPIO 132~135, 136, 137 */
	if ((gpio_request(132, "GPIO132") == 0) &&
	    (gpio_direction_output(132, 1) == 0)) {
		gpio_export(132, 0);
	} else {
		printk(KERN_ERR "could not obtain gpio for GPIO132\n");
	}

	if ((gpio_request(133, "GPIO133") == 0) &&
	    (gpio_direction_output(133, 1) == 0)) {
		gpio_export(133, 0);
	} else {
		printk(KERN_ERR "could not obtain gpio for GPIO133\n");
	}

	if ((gpio_request(134, "GPIO134") == 0) &&
	    (gpio_direction_output(134, 1) == 0)) {
		gpio_export(134, 0);
	} else {
		printk(KERN_ERR "could not obtain gpio for GPIO134\n");
	}

	if ((gpio_request(135, "GPIO135") == 0) &&
	    (gpio_direction_output(135, 1) == 0)) {
		gpio_export(135, 0);
	} else {
		printk(KERN_ERR "could not obtain gpio for GPIO135\n");
	}

	if ((gpio_request(136, "GPIO136") == 0) &&
	    (gpio_direction_output(136, 1) == 0)) {
		gpio_export(136, 0);
	} else {
		printk(KERN_ERR "could not obtain gpio for GPIO136\n");
	}

	if ((gpio_request(137, "GPIO137") == 0) &&
	    (gpio_direction_output(137, 1) == 0)) {
		gpio_export(137, 0);
	} else {
		printk(KERN_ERR "could not obtain gpio for GPIO137\n");
	}

	return 0;
}

static void __exit trainer_gpio_exit(void)
{
        printk(KERN_INFO "Beagle expansionboard: Unexporting GPIOs 130-141,162 to userspace\n");
        gpio_unexport(130);
        gpio_unexport(131);
        gpio_unexport(132);
        gpio_unexport(133);
        gpio_unexport(134);
        gpio_unexport(135);
        gpio_unexport(136);
        gpio_unexport(137);
        gpio_unexport(138);
        gpio_unexport(139);
        gpio_unexport(140);
        gpio_unexport(141);
        gpio_unexport(162);
}

module_init(trainer_gpio_init);
module_exit(trainer_gpio_exit);

