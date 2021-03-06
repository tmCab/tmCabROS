/*
 * Copyright (c) 2011, Dirk Thomas, TU Darmstadt
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the TU Darmstadt nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef rqt_tm_operation__TmOperation_H
#define rqt_tm_operation__TmOperation_H

#include "tm_cab/SAFE_CURR.h"

#include "tm_cab/SAFE_FORCE.h"

#include "tm_cab/SAFE_POS.h"

#include "tm_cab/SAFE_POS_E.h"

#include "tm_cab/SAFE_PWM.h"

#include "tm_cab/SAFE_SPEED.h"

#include "tm_cab/SELECT_CTL.h"

#include "tm_cab/SET_INTER.h"

#include "tm_cab/SAFE_STATE.h"

#include "tm_cab/SET_SYS_FS.h"

#include "tm_cab/SET_PAR_PID.h"

#include "tm_cab/POS_REF.h"

#include "tm_cab/START.h"

#include "tm_cab/STOP.h"

#include "tm_cab/START_TM_CTL.h"

#include "tm_cab/STOP_TM_CTL.h"

#include "tm_cab/PTP_TM_CTL.h"

#include "tm_cab/set_par.h"

#include "tm_cab/set_pwm_pars.h"

#include "tm_cab/jnt_traj.h"

#include "tm_cab/CTL_MODE.h"

#include <std_srvs/Trigger.h>

#include <std_msgs/Bool.h>

#include <tm_cab/SYS_STATUS.h>

#include <rqt_gui_cpp/plugin.h>

#include <ui_tm_operation.h>

#include <ros/ros.h>

#include <ros/macros.h>

#include <QList>
#include <QString>
#include <QSize>
#include <QWidget>

#include <vector>
#include <string>

namespace rqt_tm_operation {

bool isFloat(std::string myString);

class TmOperation: public rqt_gui_cpp::Plugin {

Q_OBJECT

public:

	TmOperation();

	virtual void initPlugin(qt_gui_cpp::PluginContext& context);

	virtual void shutdownPlugin();

	virtual void saveSettings(qt_gui_cpp::Settings& plugin_settings,
			qt_gui_cpp::Settings& instance_settings) const;

	virtual void restoreSettings(const qt_gui_cpp::Settings& plugin_settings,
			const qt_gui_cpp::Settings& instance_settings);

protected slots:

	virtual void ackSafety();

	virtual void setSafety();

	virtual void ctlParSelected(const QString & parName);

	virtual void setCtlPars();

	virtual void EnableIdx(int index);

	virtual void toggelIndex();

	virtual void toggelIndexPosRef();

	virtual void toggelIndexNegRef();

	virtual void toggelOperation();

	virtual void selOpMode();

	virtual void ptpExe();

	virtual void goHome();

	virtual void jntTrajExe();

	virtual void ptpModLabels(const QString & ptpMode);

	virtual void updateSensK();

	virtual void updateScaleK();

	virtual void sysStatusUpdated(const tm_cab::SYS_STATUS& msg);

	virtual void toggleGComp ( int state );

	virtual void toggleIdxPose ( int state );

	virtual void trajVarSelected(const QString & varName);

signals:

	void processStatusUpdate(const tm_cab::SYS_STATUS& msg);

protected:

	virtual void callbackSysStatus(const tm_cab::SYS_STATUS& msg);

	Ui::TmOperationWidget ui_;

	QWidget* widget_;

	ros::Subscriber sysStatS_;

	ros::Publisher posRefPub_;

	ros::Publisher setGCompPub_;

private:

	virtual void processSysStatus(QTextBrowser * sysText,
			const tm_cab::SYS_STATUS & sysStatus);

	virtual void processJointStatus(QTextBrowser * jointText,
			const tm_cab::SYS_STATUS::_j1_stat_type & jointStatus);

	int jointIdxRunning_;

	bool jntCtlSelected_;

	bool sysRunning_;
};

}

#endif
