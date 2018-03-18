#include <stdio.h>
#include <string.h>

#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/pinctrl/pinctrl.h>

#include "pinctrl-mvebu.h"

int
mvebu_pinctrl_simple_regmap_probe(struct platform_device *pdev,
    struct device *syscon_dev, u32 offset)
{
	static int header = 1;
	struct mvebu_pinctrl_soc_info *soc = pdev->dev.platform_data;
	struct mvebu_mpp_ctrl_setting *setting;
	char *name, *p;
	int i;

	name = strdup(pdev->name);
	p = strrchr(name, '_');
	*p = 0;
	p = strrchr(name, '_');
	*p = 0;

	if (header) {
		printf("/* Public Domain */\n");
		printf("\n");
		header = 0;
	}

	printf("\n");

	printf("struct mvpinctrl_pin %s_pins[] = {\n", name);
	for (i = 0; i < soc->nmodes; i++) {
		setting = soc->modes[i].settings;
		while (setting->name) {
			printf("\tMPP(%d, \"%s\", %d),\n", soc->modes[i].pid,
			    setting->name, setting->val);
			setting++;
		}
	}
	printf("};\n");

	return 0;
}

int
mvebu_pinctrl_simple_mmio_probe(struct platform_device *pdev)
{
	return mvebu_pinctrl_simple_regmap_probe(pdev, NULL, 0);
}

int
mvebu_regmap_mpp_ctrl_get(struct mvebu_mpp_ctrl_data *data,
    unsigned pid, unsigned long *config)
{
	return 0;
}

int
mvebu_regmap_mpp_ctrl_set(struct mvebu_mpp_ctrl_data *data,
    unsigned pid, unsigned long config)
{
	return 0;
}

int
mvebu_mmio_mpp_ctrl_get(struct mvebu_mpp_ctrl_data *data,
    unsigned pid, unsigned long *config)
{
	return 0;
}

int
mvebu_mmio_mpp_ctrl_set(struct mvebu_mpp_ctrl_data *data,
    unsigned pid, unsigned long config)
{
	return 0;
}

void
driver_register(struct platform_driver *driver, const char *name)
{
	struct platform_device pdev;

	pdev.name = name;
	pdev.dev.parent = &pdev.dev;
	driver->probe(&pdev);
}

int
main(void)
{
}
