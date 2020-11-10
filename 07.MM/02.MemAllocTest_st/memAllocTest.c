#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>

#include <linux/_______.h>

static int *my_data=NULL;

int memAllocTest_init(void)
{
	int i;

	printk(KERN_INFO "memAllocTest Module Load Start!! ....\n");

	//memory allocation
	my_data = ___________
	if(!my_data) return -1;

	for(i=0; i<5; i++) {
		my_data[i] = 70+i;
	}
	for(i=0; i<5; i++) {
		printk("my_data[%d] : %d\n", i, my_data[i]);
	}
	
	printk(KERN_INFO "memAllocTest Module Load End!! ....\n");

	return 0;
}

void memAllocTest_exit(void)
{
	//int i;

	printk("memAllocTest Module Unload Start....\n");

	//memory free
	if(my_data) _________

	printk("memAllocTest Module Unload End....\n");
}

module_init(memAllocTest_init);
module_exit(memAllocTest_exit);

MODULE_LICENSE("Dual BSD/GPL");


