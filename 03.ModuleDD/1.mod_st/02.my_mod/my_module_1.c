#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

int MY_NUM;

int my_init(void)
{
	MY_NUM++;
	printk(KERN_INFO "MY Module_1 is Loaded1(MY_NUM:%d)!! ....\n", MY_NUM);
	printk(KERN_EMERG "Hi,Hi, I'm my_module....\n");
	//MOD_INC_USE_COUNT;
	return 0;
}

void my_exit(void)
{
	printk(KERN_INFO "MY Module_1 is Unloaded(MY_NUM:%d)....\n", MY_NUM);
	//MOD_DEC_USE_COUNT;
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("Dual BSD/GPL");
