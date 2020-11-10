#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/delay.h>

#include <linux/______.h>
//#include <linux/gfp.h>
//#include <linux/mm.h>

struct my_struct {
	char name[50];
	int age;
	int score;
};

static ___________ *my_cachep=NULL;
struct my_struct *my_obj=NULL;

int slabTest_init(void)
{
	printk(KERN_INFO "slabTest Module is Load Start!! ....\n");

	//create cache
	my_cachep = _________(
				"my_struct",			//name
				___________,			//object size
				0,					//alignment
				//SLAB_HWCACHE_ALIGN,	//flags
				0,					//flags
				NULL				//constructor
			);

	if(my_cachep==NULL) return -1;
	
#ifndef HOST
	printk("Cache Name : %s\n", kmem_cache_name(my_cachep));
#endif
	printk("Cache Object Size : %d\n", kmem_cache_size(my_cachep));

	//alloc object memory from cache
	if(( my_obj = ______________ )) {

		strcpy(my_obj->name, "kim");
		my_obj->age = 17;
		my_obj->score = 77;

	} else {
		printk("my_cachep object alloc error!!\n");

		//destroy slab cache
		______________
		return -2;
	}

	printk("my_obj:%s,%d,%d\n", my_obj->name, my_obj->age, my_obj->score);

	printk(KERN_INFO "slabTest Module is Load End!! ....\n");

	return 0;
}

void slabTest_exit(void)
{
	printk("slabTest Module is Unload Start....\n");

	//free object memory
	if(my_obj) {
		____________
		printk("free object memory....\n");
		//printk("my_obj:%s,%d,%d\n", my_obj->name, my_obj->age, my_obj->score);
	}

	//destroy slab cache
	if(my_cachep) {
		___________
		printk("destroy slab cache....\n");
		//printk("Cache Name : %s\n", kmem_cache_name(my_cachep));
		//printk("Cache Object Size : %d\n", kmem_cache_size(my_cachep));
	}

	printk("slabTest Module is Unload End....\n");
}

module_init(slabTest_init);
module_exit(slabTest_exit);

MODULE_LICENSE("Dual BSD/GPL");


