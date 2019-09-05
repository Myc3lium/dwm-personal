static int attachbelow = 1;    /* 1 means attach at the end */
static void attachBelow(Client *c);

void
attachBelow(Client *c)
{
	//If there is nothing on the monitor or the selected client is floating, attach as normal
	if(c->mon->sel == NULL || c->mon->sel->isfloating) {
		attach(c);
		return;
	}

	//Set the new client's next property to the same as the currently selected clients next
	c->next = c->mon->sel->next;
	//Set the currently selected clients next property to the new client
	c->mon->sel->next = c;

}

void toggleAttachBelow()
{
	attachbelow = !attachbelow;
}
