////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Astrodynamics
/// @file           OpenSpaceToolkit/Astrodynamics/Flight/System.test.cpp
/// @author         Antoine Paletta <antoine.paletta@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Astrodynamics/Flight/System.hpp>

#include <OpenSpaceToolkit/Physics/Units/Mass.hpp>

#include <OpenSpaceToolkit/Mathematics/Objects/Vector.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Objects/Cuboid.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Objects/Point.hpp>
#include <OpenSpaceToolkit/Mathematics/Geometry/3D/Objects/Composite.hpp>

#include <OpenSpaceToolkit/Core/Types/Real.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, Constructor)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    // Normal constructor
    {

        // Define satellite mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define satellite geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        // Construct System object
        EXPECT_NO_THROW(System system( systemMass, systemGeometry )) ;

    }

    // Copy constructor
    {

        // Define satellite mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define satellite geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        // Construct System object
        const System system = { systemMass, systemGeometry } ;

        EXPECT_NO_THROW(System systemCopy(system)) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, EqualToOperator)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    // Normal constructor
    {

        // Define system mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define system geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        const System system = {systemMass, systemGeometry} ;

        EXPECT_TRUE(system == system) ;

        // Test for different mass
        const Mass systemMass_0 = { 90.0, Mass::Unit::Kilogram } ;
        const System system_1 = { systemMass_0, systemGeometry } ;

        EXPECT_FALSE(system == system_1) ;

        // Test for different geometry
        const Point center_0 = { 1.0, 0.0, 0.0 } ;
        const Cuboid systemCuboid_0 = {center_0, axes, extent} ;
        const Composite systemGeometry_0(systemCuboid_0) ;
        const System system_2 = { systemMass, systemGeometry_0 } ;

        EXPECT_FALSE(system == system_2) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, NotEqualToOperator)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    // Normal constructor
    {

        // Define system mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define system geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        const System system = {systemMass, systemGeometry} ;

        EXPECT_FALSE(system != system) ;

        // Test for different mass
        const Mass systemMass_0 = { 90.0, Mass::Unit::Kilogram } ;
        const System system_1 = { systemMass_0, systemGeometry } ;

        EXPECT_TRUE(system != system_1) ;

        // Test for different geometry
        const Point center_0 = { 1.0, 0.0, 0.0 } ;
        const Cuboid systemCuboid_0 = {center_0, axes, extent} ;
        const Composite systemGeometry_0(systemCuboid_0) ;
        const System system_2 = { systemMass, systemGeometry_0 } ;

        EXPECT_TRUE(system != system_2) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, IsDefined)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    {

        // Define satellite mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define satellite geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        // Construct System object
        const System system = { systemMass, systemGeometry } ;

        EXPECT_TRUE(system.isDefined()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, StreamOperator)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    {

        // Define satellite mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define satellite geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        // Construct System object
        const System system = { systemMass, systemGeometry } ;

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << system << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, Print)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    {

        // Define satellite mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define satellite geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        // Construct System object
        const System system = { systemMass, systemGeometry } ;

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(system.print(std::cout, true)) ;
        EXPECT_NO_THROW(system.print(std::cout, false)) ;
        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, getMass)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    {

        // Define satellite mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define satellite geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        // Construct System object
        const System system = { systemMass, systemGeometry } ;

        EXPECT_EQ(system.getMass(), systemMass) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Flight_System, getGeometry)
{

    using ostk::core::types::Real ;
    using ostk::core::types::String ;
    using ostk::core::types::Integer ;

    using ostk::math::obj::Matrix3d ;
    using ostk::math::geom::d3::objects::Cuboid ;
    using ostk::math::geom::d3::objects::Composite ;
    using ostk::math::obj::Vector3d ;
    using ostk::math::geom::d3::objects::Point ;

    using ostk::physics::units::Mass ;

    using ostk::astro::flight::System ;

    {

        // Define satellite mass
        const Mass systemMass = { 100.0, Mass::Unit::Kilogram } ;

        // Define satellite geometry
        const Point center = { 0.0, 0.0, 0.0 } ;
        const std::array<Vector3d, 3> axes = { Vector3d { 1.0, 0.0, 0.0 }, Vector3d { 0.0, 1.0, 0.0 }, Vector3d { 0.0, 0.0, 1.0 } } ;
        const std::array<Real, 3> extent = { 1.0, 2.0, 3.0 } ;

        const Cuboid systemCuboid = { center, axes, extent } ;
        const Composite systemGeometry(systemCuboid) ;

        // Construct System object
        const System system = { systemMass, systemGeometry } ;

        EXPECT_EQ(system.getGeometry(), systemGeometry) ;

    }

}
