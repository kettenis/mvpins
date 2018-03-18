struct device {
	struct device *parent;
	void *platform_data;
	unsigned long variant;
};
