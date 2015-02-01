/**
 ******************************************************************************
 * Xenia : Xbox 360 Emulator Research Project                                 *
 ******************************************************************************
 * Copyright 2013 Ben Vanik. All rights reserved.                             *
 * Released under the BSD license - see LICENSE in the root for more details. *
 ******************************************************************************
 */

#ifndef XENIA_KERNEL_FS_DEVICE_H_
#define XENIA_KERNEL_FS_DEVICE_H_

#include <memory>
#include <string>

#include "xenia/common.h"
#include "xenia/kernel/fs/entry.h"

namespace xe {
namespace kernel {
namespace fs {

class Device {
 public:
  Device(const std::string& path);
  virtual ~Device();

  const std::string& path() const { return path_; }

  virtual std::unique_ptr<Entry> ResolvePath(const char* path) = 0;

  virtual X_STATUS QueryVolume(XVolumeInfo* out_info, size_t length);
  virtual X_STATUS QueryFileSystemAttributes(XFileSystemAttributeInfo* out_info,
                                             size_t length);

 protected:
  std::string path_;
};

}  // namespace fs
}  // namespace kernel
}  // namespace xe

#endif  // XENIA_KERNEL_FS_DEVICE_H_
