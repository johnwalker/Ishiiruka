// Copyright 2016 Dolphin Emulator Project
// Licensed under GPLv2+
// Refer to the license.txt file included.

#pragma once

#include <cstddef>
#include <string>

#include "Common/CommonTypes.h"
#include "Core/IOS/Device.h"
#include "Core/IOS/IOS.h"

class PointerWrap;
class SysConf;

namespace IOS
{
namespace HLE
{
void BackUpBTInfoSection(const SysConf* sysconf);
void RestoreBTInfoSection(SysConf* sysconf);

namespace Device
{
class BluetoothBase : public Device
{
public:
	using Device::Device;
	virtual void UpdateSyncButtonState(bool is_held) {}
	virtual void TriggerSyncButtonPressedEvent() {}
	virtual void TriggerSyncButtonHeldEvent() {}
protected:
	static constexpr int ACL_PKT_SIZE = 339;
	static constexpr int ACL_PKT_NUM = 10;
	static constexpr int SCO_PKT_SIZE = 64;
	static constexpr int SCO_PKT_NUM = 0;

	enum USBEndpoint
	{
		HCI_CTRL = 0x00,
		HCI_EVENT = 0x81,
		ACL_DATA_IN = 0x82,
		ACL_DATA_OUT = 0x02
	};
};
}  // namespace Device
}  // namespace HLE
}  // namespace IOS
