// Copyright 2015-2019 Autoware Foundation. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// Authors: Ryohsuke Mitsudome

#ifndef LANELET2_EXTENSION__REGULATORY_ELEMENTS__DETECTION_AREA_HPP_
#define LANELET2_EXTENSION__REGULATORY_ELEMENTS__DETECTION_AREA_HPP_

// NOLINTBEGIN(readability-identifier-naming)

#include <autoware_lanelet2_extension/regulatory_elements/Forward.hpp>

#include <lanelet2_core/primitives/Lanelet.h>

#include <memory>

namespace lanelet::autoware
{
class DetectionArea : public lanelet::RegulatoryElement
{
public:
  using Ptr = std::shared_ptr<DetectionArea>;
  static constexpr char RuleName[] = "detection_area";

  //! Directly construct a stop line from its required rule parameters.
  //! Might modify the input data in oder to get correct tags.
  static Ptr make(
    Id id, const AttributeMap & attributes, const Polygons3d & detectionAreas,
    const LineString3d & stopLine)
  {
    return Ptr{new DetectionArea(id, attributes, detectionAreas, stopLine)};
  }

  /**
   * @brief get the relevant detection_areas
   * @return detection_areas
   */
  [[nodiscard]] ConstPolygons3d detectionAreas() const;
  [[nodiscard]] Polygons3d detectionAreas();

  /**
   * @brief add a new detection area
   * @param primitive detection area to add
   */
  void addDetectionArea(const Polygon3d & primitive);

  /**
   * @brief remove a detection area
   * @param primitive the primitive
   * @return true if the detection area existed and was removed
   */
  bool removeDetectionArea(const Polygon3d & primitive);

  /**
   * @brief get the stop line for the detection area
   * @return the stop line as LineString
   */
  [[nodiscard]] ConstLineString3d stopLine() const;
  [[nodiscard]] LineString3d stopLine();

  /**
   * @brief set a new stop line, overwrite the old one
   * @param stopLine new stop line
   */
  void setStopLine(const LineString3d & stopLine);

  //! Deletes the stop line
  void removeStopLine();

private:
  DetectionArea(
    Id id, const AttributeMap & attributes, const Polygons3d & detectionAreas,
    const LineString3d & stopLine);

  // the following lines are required so that lanelet2 can create this object
  // when loading a map with this regulatory element
  friend class RegisterRegulatoryElement<DetectionArea>;
  explicit DetectionArea(const lanelet::RegulatoryElementDataPtr & data);
};

}  // namespace lanelet::autoware

// NOLINTEND(readability-identifier-naming)

#endif  // LANELET2_EXTENSION__REGULATORY_ELEMENTS__DETECTION_AREA_HPP_
