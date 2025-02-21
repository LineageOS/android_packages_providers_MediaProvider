/*
 * Copyright (C) 2019 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specic language governing permissions and
 * limitations under the License.
 */

#ifndef MEDIAPROVIDER_JNI_UTILS_H_
#define MEDIAPROVIDER_JNI_UTILS_H_

#include <string>

namespace mediaprovider {
namespace fuse {
static constexpr char STORAGE_PREFIX[] = "/storage";
static constexpr char VOLUME_INTERNAL[] = "internal";
static constexpr char VOLUME_EXTERNAL_PRIMARY[] = "external_primary";
static constexpr char PRIMARY_VOLUME_PREFIX[] = "/storage/emulated";

/**
 * Returns true if the given path (ignoring case) is mounted for any
 * userid. Mounted paths are:
 * "/storage/emulated/<userid>/Android"
 * "/storage/emulated/<userid>/Android/data"
 * "/storage/emulated/<userid>/Android/obb" *
 */
bool containsMount(const std::string& path);

/**
 * Returns the volume name extracted from a given path.
 */
std::string getVolumeNameFromPath(const std::string& path);

/**
 * Removes any Unicode default ignorable codepoints from the provided string_view.
 * Returns an empty string if a decoding failure occurs.
 * Requires SDK 31 or above to use the required libicu functions. Otherwise, returns empty string.
 * @param str The string_view from which to remove Unicode default ignorable codepoints.
 * @return A new string without the default ignorable codepoints, or an empty string
 *         if a decoding failure occurs or we are SDK < 31.
 */
std::string removeDefaultIgnorableCodepoints(const std::string_view& str);

}  // namespace fuse
}  // namespace mediaprovider

#endif  // MEDIAPROVIDER_JNI_UTILS_H_
