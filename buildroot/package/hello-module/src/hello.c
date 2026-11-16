#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init mymod_init(void)
{
    printk("Hello World\n");
    return 0;
}

static void __exit mymod_exit(void)
{
    printk("Bye Bye World\n");
}

module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");
