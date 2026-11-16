HELLO_MODULE_SITE = $(TOPDIR)/package/hello-module/src
HELLO_MODULE_SITE_METHOD = local

$(eval $(kernel-module))
$(eval $(generic-package))

