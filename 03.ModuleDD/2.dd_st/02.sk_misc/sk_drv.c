#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

#include <linux/fs.h>
#include <linux/uaccess.h>		//copy_from_user(). copy_to_user()
#include <linux/slab.h>			//kmalloc

#include <linux/_________.h>

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

struct file_operations sk_fops = {
    read:       sk_read,
    write:      sk_write,
    open:       sk_open,
//    ioctl:		sk_ioctl,
    unlocked_ioctl:		sk_ioctl,
    release:    sk_release
};

__________ sk_miscdev = {
	.name		= "sk",
//	.minor		= 253,
	.minor		= __________,
	.fops		= &sk_fops,
};

int sk_init(void)
{
	int error;

	printk("SK Module id Up....\n");	

	error = ____________
	if(error < 0) {
		printk(KERN_WARNING "sk:misc_register Fail!!\n");
		return error;
	}
	printk(KERN_WARNING "sk:misc_register OK!!\n");

	printk(KERN_WARNING "SK Module Insert Done!!\n");
	return 0;
}

void sk_exit(void)
{
	printk("SK Module id Down....\n");

	____________

	printk(KERN_WARNING "SK Module Delete Done!!\n");
}

module_init(sk_init);
module_exit(sk_exit);

MODULE_LICENSE("Dual BSD/GPL");
