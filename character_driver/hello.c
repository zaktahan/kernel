#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include<linux/cdev.h>
dev_t dev;
static const struct file_operations hello_fops= {
.ower= THIS_MODULE,
};
struct cdev hello_cdev;
static int __init mymod_init(void)
{
int ret=alloc_chrdev_region(&dev, 0, 1, "hello");
if(ret<0)
{
printk("allocate failed\n");
return ret;
}
cdev_init(&hello_cdev, &hello_fops);
ret=cdev_add (&hello_cdev,dev,1);
if(ret<0)
{
printk("dev registrate failed\n");
unregister_chrdev_region(dev, 1);
return ret;
}
    printk("Hello World\n");
    return 0;
}

static void __exit mymod_exit(void)
{
    printk("Bye Bye World\n");
cdev_del (&hello_cdev);
unregister_chrdev_region (dev,1);
}
module_init(mymod_init);
module_exit(mymod_exit);

MODULE_LICENSE("GPL");


