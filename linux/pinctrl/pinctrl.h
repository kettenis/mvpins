struct pinctrl_pin_desc {
	unsigned number;
	const char *name;
};

#define PINCTRL_PIN(a, b) { .number = a, .name = b }

struct pinctrl_gpio_range {
	const char *name;
	unsigned id;
	unsigned pin_base;
	unsigned base;
	unsigned npins;
};
