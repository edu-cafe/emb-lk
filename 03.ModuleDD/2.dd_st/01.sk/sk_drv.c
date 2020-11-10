#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

_____________

int sk_major=0;

int sk_open (struct inode *inode, struct file *filp)
{
	printk(KERN_WARNING "[SK_DD]open..\n");
	
	return 0;
}

int sk_release (struct inode *inode, struct file *filp)
{
	printk(KERN_WARNING "[SK_DD]release..\n");
	return 0;
}

ssize_t sk_read (struct file *filp, char *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_WARNING "[SK_DD]read..\n");
	return count;
}


ssize_t sk_write (struct file *filp, const char *buf, size_t count, loff_t *f_pos)
{
	printk(KERN_WARNING "[SK_DD]write..\n");
	return count;
}


//int sk_ioctl(struct inode *inode, struct file *filp, unsigned int cmd, unsigned long arg)
long sk_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	printk(KERN_WARNING "[SK_DD]ioctl..\n");
	return 0;
}

_____________ sk_fops = {
    read:       sk_read,
    write:      sk_write,
    open:       sk_open,
//    ioctl:		sk_ioctl,
    unlocked_ioctl:		sk_ioctl,
    release:    sk_release
};

int sk_init(void)
{
	int error;

	printk("SK Module id Up....\n");

	error = ______________
	if(error < 0) {
		printk(KERN_WARNING "sk:register_chrdev() error!!\n");
		return error;
	} else if(sk_major==0) sk_major = error;
	printk("sk:register_chrdev() ok! => major_num:%d\n", sk_major);

	printk(KERN_WARNING "SK Module Insert Done!!\n");
	return 0;
}

void sk_exit(void)
{
	printk("SK Module id Down....\n");

	_______________

	printk(KERN_WARNING "SK Module Delete Done!!\n");
}

module_init(sk_init);
module_exit(sk_exit);

MODULE_LICENSE("Dual BSD/GPL");
