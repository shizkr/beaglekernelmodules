/*
 * GPIO test program
 *
 * Denny (Dongsung) Yang
 *
 * Licensed under the GPL-2 or later
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

#define LED1 132
#define LED2 133
#define LED3 134
#define LED4 135
 
#define GPIO_DIR_IN	0
#define GPIO_DIR_OUT	1
 
int gpio_export(unsigned gpio)
{
	int fd, len;
	char buf[11];
 
	fd = open("/sys/class/gpio/export", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return fd;
	}
 
	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	close(fd);
 
	return 0;
}
 
int gpio_unexport(unsigned gpio)
{
	int fd, len;
	char buf[11];
 
	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd < 0) {
		perror("gpio/export");
		return fd;
	}
 
	len = snprintf(buf, sizeof(buf), "%d", gpio);
	write(fd, buf, len);
	close(fd);
	return 0;
}
 
int gpio_dir(unsigned gpio, unsigned dir)
{
	int fd, len;
	char buf[60];
 
	len = snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/direction", gpio);
 
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/direction");
		return fd;
	}
 
	if (dir == GPIO_DIR_OUT)
		write(fd, "out", 4);
	else
		write(fd, "in", 3);
 
	close(fd);
	return 0;
}
 
int gpio_dir_out(unsigned gpio)
{
	return gpio_dir(gpio, GPIO_DIR_OUT);
}
 
int gpio_dir_in(unsigned gpio)
{
	return gpio_dir(gpio, GPIO_DIR_IN);
}
 
int gpio_value(unsigned gpio, unsigned value)
{
	int fd, len;
	char buf[60];
 
	len = snprintf(buf, sizeof(buf), "/sys/class/gpio/gpio%d/value", gpio);
 
	fd = open(buf, O_WRONLY);
	if (fd < 0) {
		perror("gpio/value");
		return fd;
	}
 
	if (value)
		write(fd, "1", 2);
	else
		write(fd, "0", 2);
 
	close(fd);
	return 0;
}

void led_control(unsigned value)
{
	if (value & 0x01)
		gpio_value(LED1, 0);	
	else
		gpio_value(LED1, 1);

	if (value & 0x02)
		gpio_value(LED2, 0);	
	else
		gpio_value(LED2, 1);

	if (value & 0x04)
		gpio_value(LED3, 0);	
	else
		gpio_value(LED3, 1);

	if (value & 0x08)
		gpio_value(LED4, 0);	
	else
		gpio_value(LED4, 1);
}
 
int main(void)
{
	int i=200000;

	while(i--) {
		led_control(1);
		usleep(i);
		led_control(4);
		usleep(i);
		led_control(8);
		usleep(i);
		led_control(2);
		usleep(i);
		if ( i == 2000 ) i = 200000;
		printf("%d\n", i);
	}
	return 0;
}

