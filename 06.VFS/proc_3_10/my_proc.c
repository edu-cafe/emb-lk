#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

#include <linux/proc_fs.h>
#include <linux/mutex.h>
#include <linux/seq_file.h>
#include <linux/list.h>

struct my_device {
	char *name;
	int d1;
	int d2;
	struct list_head list;
};

struct my_device data1 = {
	"mydevice1",
	11,
	101,
	LIST_HEAD_INIT(data1.list)
};
struct my_device data2 = {
	"mydevice2",
	21,
	201,
	LIST_HEAD_INIT(data2.list)
};
struct my_device data3 = {
	"mydevice3",
	31,
	301,
	LIST_HEAD_INIT(data3.list)
};

static LIST_HEAD(my_list);
static DEFINE_MUTEX(my_mtx);

static   struct proc_dir_entry * my_proc_root_entry=NULL;
static   struct proc_dir_entry * my_proc_entry=NULL;

static void *my_seq_start(struct seq_file *seq, loff_t *pos)
{
	mutex_lock(&my_mtx);
	return seq_list_start(&my_list, *pos);
}

static void *my_seq_next(struct seq_file *seq, void *v, loff_t *pos)
{
	return seq_list_next(v, &my_list, pos);
}

static void my_seq_stop(struct seq_file *seq, void *v)
{
	mutex_unlock(&my_mtx);
}

static int my_seq_show(struct seq_file *seq, void *v)
{
	const struct my_device *p = list_entry(v, struct my_device, list);
	seq_printf(seq, "%s %3i %3i\n", p->name, p->d1, p->d2);
	return 0;
}


static const struct seq_operations my_seq_ops = {
	.start = my_seq_start,
	.next  = my_seq_next,
	.stop  = my_seq_stop,
	.show  = my_seq_show,
};

static int my_seq_open(struct inode *inode, struct file *file)
{
	list_add(&data1.list, &my_list);
	list_add(&data2.list, &my_list);
	list_add(&data3.list, &my_list);
	return seq_open(file, &my_seq_ops);
}

static const struct file_operations my_proc_fops = {
	.owner	 = THIS_MODULE,
	.open    = my_seq_open,
	.read    = seq_read,
	.llseek  = seq_lseek,
	.release = seq_release,
};

static int __init my_proc_init(void)
{

    printk("----->MY_PROC Module Loading!!\n");

	my_proc_entry = proc_create("my_proc", S_IRUGO, NULL, &my_proc_fops);

    return 0;
}

static void __exit my_proc_exit(void)
{
    printk("----->MY_PROC Module UnLoading!!\n");
    remove_proc_entry("my_proc", my_proc_root_entry);
}

module_init(my_proc_init);
module_exit(my_proc_exit);

MODULE_LICENSE("Dual BSD/GPL");
