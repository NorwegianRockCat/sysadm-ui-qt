//===========================================
//  PC-BSD source code
//  Copyright (c) 2016, PC-BSD Software/iXsystems
//  Available under the 3-clause BSD license
//  See the LICENSE file for full details
//===========================================
#ifndef _PCBSD_SYSADM_CLIENT_BEADM_PAGE_H
#define _PCBSD_SYSADM_CLIENT_BEADM_PAGE_H
#include "../globals.h"
#include "../PageWidget.h"


//==============================================================
//  DON"T FORGET TO ADD YOUR NEW PAGE TO THE "getPage.h" FILE!!!!
//==============================================================

namespace Ui{
	class page_beadm_ui; //this is the name of the main widget/object in the QtDesigner form
};

class beadm_page : public PageWidget{
	Q_OBJECT
public:
	beadm_page(QWidget *parent, sysadm_client *core);
	~beadm_page();

	//Initialize the CORE <-->Page connections
	void setupCore();
	//Page embedded, go ahead and startup any core requests
	void startPage();

	QString pageID(){ return "sysadm/beadm"; } //ID is used to identify which type of page this is
	void ParseReply(QString, QString, QString, QJsonValue);

private:
	Ui::page_beadm_ui *ui;
	void startingRequest(QString notice);

private slots:

	//GUI enable/disable based on selection
	void updateButtons();

	//GUI Buttons
	void create_be();
	void clone_be(bool invalidname = false);
	void delete_be();
	void rename_be();
	void mount_be();
	void unmount_be();
	void activate_be();

	void updateList();

};
#endif
