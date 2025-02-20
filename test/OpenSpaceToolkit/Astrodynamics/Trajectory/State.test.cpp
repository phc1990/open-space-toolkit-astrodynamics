////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Open Space Toolkit ▸ Astrodynamics
/// @file           OpenSpaceToolkit/Astrodynamics/Trajectory/State.test.cpp
/// @author         Vishwa Shah <vishwa@loftorbital.com>
/// @license        Apache License 2.0

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <OpenSpaceToolkit/Astrodynamics/Trajectory/State.hpp>

#include <Global.test.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, Constructor)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        EXPECT_NO_THROW(State state(instant, position, velocity) ;) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, EqualToOperator)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_TRUE(state == state) ;

    }

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const Instant instant_1 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant_1, position, velocity } ;

        const Instant instant_2 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 1), Scale::UTC) ;

        const State state_2 = { instant_2, position, velocity } ;

        EXPECT_FALSE(state_1 == state_2) ;

    }

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_FALSE(State::Undefined() == state) ;
        EXPECT_FALSE(state == State::Undefined()) ;
        EXPECT_FALSE(State::Undefined() == State::Undefined()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, NotEqualToOperator)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const Instant instant_1 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant_1, position, velocity } ;

        const Instant instant_2 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 1), Scale::UTC) ;

        const State state_2 = { instant_2, position, velocity } ;

        EXPECT_TRUE(state_1 != state_2) ;

    }

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_FALSE(state != state) ;

    }

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_TRUE(State::Undefined() != state) ;
        EXPECT_TRUE(state != State::Undefined()) ;
        EXPECT_TRUE(State::Undefined() != State::Undefined()) ;

    }

}


TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, AdditionOperator)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const Instant instant_1 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant_1, position, velocity } ;


        EXPECT_ANY_THROW(state_1 + State::Undefined()) ;

    }

    {

        const Position position_1 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;
        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant, position_1, velocity } ;

        const Position position_2 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::ITRF()) ;

        const State state_2 = { instant, position_2, velocity } ;

        EXPECT_ANY_THROW(state_1 + state_2) ;

    }

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity_1 = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;
        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant, position, velocity_1 } ;

        const Velocity velocity_2 = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::ITRF()) ;

        const State state_2 = { instant, position, velocity_2 } ;

        EXPECT_ANY_THROW(state_1 + state_2) ;

    }

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const Instant instant_1 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant_1, position, velocity } ;

        const Instant instant_2 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 1), Scale::UTC) ;

        const State state_2 = { instant_2, position, velocity } ;

        EXPECT_ANY_THROW(state_1 + state_2) ;

    }

    {

        const Position position_1 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;
        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant, position_1, velocity } ;

        const Position position_2 = Position({ 1.2, 3.4, 5.6 }, Position::Unit::Foot, Frame::ITRF()) ;

        const State state_2 = { instant, position_2, velocity } ;

        EXPECT_ANY_THROW(state_1 + state_2) ;

    }

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position_1 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity_1 = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state_1 = { instant, position_1, velocity_1 } ;

        const Position position_2 = Position::Meters({ 0.2, 0.4, 0.6 }, Frame::GCRF()) ;
        const Velocity velocity_2 = Velocity::MetersPerSecond({ 7.0, 8.0, 1.0 }, Frame::GCRF()) ;

        const State state_2 = { instant, position_2, velocity_2 } ;

        const Position positionExpected = Position::Meters({ 1.4, 3.8, 6.2 }, Frame::GCRF()) ;
        const Velocity velocityExpected = Velocity::MetersPerSecond({ 14.8, 17.0, 2.2 }, Frame::GCRF()) ;

        const State stateExpected = {instant, positionExpected, velocityExpected} ;

        const State stateCalculated = state_1 + state_2 ;

        EXPECT_TRUE(stateExpected.getCoordinates().isNear(stateCalculated.getCoordinates(), 1e-12)) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, SubtractionOperator)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const Instant instant_1 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant_1, position, velocity } ;

        EXPECT_ANY_THROW(state_1 - State::Undefined()) ;

    }

    {

        const Position position_1 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;
        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant, position_1, velocity } ;

        const Position position_2 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::ITRF()) ;

        const State state_2 = { instant, position_2, velocity } ;

        EXPECT_ANY_THROW(state_1 - state_2) ;

    }

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity_1 = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;
        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant, position, velocity_1 } ;

        const Velocity velocity_2 = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::ITRF()) ;

        const State state_2 = { instant, position, velocity_2 } ;

        EXPECT_ANY_THROW(state_1 - state_2) ;

    }

    {

        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const Instant instant_1 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant_1, position, velocity } ;

        const Instant instant_2 = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 1), Scale::UTC) ;

        const State state_2 = { instant_2, position, velocity } ;

        EXPECT_ANY_THROW(state_1 - state_2) ;

    }

    {

        const Position position_1 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;
        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;

        const State state_1 = { instant, position_1, velocity } ;

        const Position position_2 = Position({ 1.2, 3.4, 5.6 }, Position::Unit::Foot, Frame::ITRF()) ;

        const State state_2 = { instant, position_2, velocity } ;

        EXPECT_ANY_THROW(state_1 - state_2) ;

    }

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position_1 = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity_1 = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state_1 = { instant, position_1, velocity_1 } ;

        const Position position_2 = Position::Meters({ 0.2, 0.4, 0.6 }, Frame::GCRF()) ;
        const Velocity velocity_2 = Velocity::MetersPerSecond({ 7.0, 8.0, 1.0 }, Frame::GCRF()) ;

        const State state_2 = { instant, position_2, velocity_2 } ;

        const Position positionExpected = Position::Meters({ 1.0, 3.0, 5.0 }, Frame::GCRF()) ;
        const Velocity velocityExpected = Velocity::MetersPerSecond({ 0.8, 1.0, 0.2 }, Frame::GCRF()) ;

        const State stateExpected = {instant, positionExpected, velocityExpected} ;

        const State stateCalculated = state_1 - state_2 ;

        EXPECT_TRUE(stateExpected.getCoordinates().isNear(stateCalculated.getCoordinates(), 1e-12)) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, StreamOperator)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << state << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

    {

        testing::internal::CaptureStdout() ;

        EXPECT_NO_THROW(std::cout << State::Undefined() << std::endl) ;

        EXPECT_FALSE(testing::internal::GetCapturedStdout().empty()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, IsDefined)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_TRUE(state.isDefined()) ;

    }

    {

        const Instant instant = Instant::Undefined() ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_FALSE(state.isDefined()) ;

    }

    {

        EXPECT_FALSE(State::Undefined().isDefined()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, Accessors)
{
    using ostk::math::obj::VectorXd ;

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_EQ(instant, state.accessInstant()) ;
        EXPECT_EQ(position, state.accessPosition()) ;
        EXPECT_EQ(velocity, state.accessVelocity()) ;

    }

    {

        EXPECT_ANY_THROW(State::Undefined().accessInstant()) ;
        EXPECT_ANY_THROW(State::Undefined().accessPosition()) ;
        EXPECT_ANY_THROW(State::Undefined().accessVelocity()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, Getters)
{

    using ostk::math::obj::VectorXd ;

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;
        VectorXd coordinates(6) ;
        coordinates << 1.2, 3.4, 5.6, 7.8, 9.0, 1.2 ;

        const State state = { instant, position, velocity } ;

        EXPECT_EQ(instant, state.getInstant()) ;
        EXPECT_EQ(position, state.getPosition()) ;
        EXPECT_EQ(velocity, state.getVelocity()) ;
        EXPECT_EQ(coordinates, state.getCoordinates()) ;

    }

    {

        EXPECT_ANY_THROW(State::Undefined().getInstant()) ;
        EXPECT_ANY_THROW(State::Undefined().getPosition()) ;
        EXPECT_ANY_THROW(State::Undefined().getVelocity()) ;
        EXPECT_ANY_THROW(State::Undefined().getCoordinates()) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, InFrame)
{

    using ostk::physics::time::Scale ;
    using ostk::physics::time::Instant ;
    using ostk::physics::time::DateTime ;
    using ostk::physics::coord::Position ;
    using ostk::physics::coord::Velocity ;
    using ostk::physics::coord::Frame ;

    using ostk::astro::trajectory::State ;

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state_GCRF_1 = { instant, position, velocity } ;

        const State state_GCRF_2 = state_GCRF_1.inFrame(Frame::GCRF()) ;

        EXPECT_EQ(state_GCRF_2, state_GCRF_1) ;

    }

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state_GCRF_1 = { instant, position, velocity } ;

        const State state_GCRF_2 = state_GCRF_1.inFrame(Frame::ITRF()) ;

        EXPECT_EQ(state_GCRF_2.getInstant(), state_GCRF_1.getInstant()) ;

        EXPECT_TRUE(state_GCRF_2.getPosition().getCoordinates().isNear({ 3.130432245445, -1.782920894026, 5.601927082917 }, 1e-12)) ;
        EXPECT_TRUE(state_GCRF_2.getVelocity().getCoordinates().isNear({ 7.449331963058, -9.290756194490, 1.213098202596 }, 1e-12)) ;

        EXPECT_EQ(state_GCRF_2.getPosition().accessFrame(), Frame::ITRF()) ;
        EXPECT_EQ(state_GCRF_2.getVelocity().accessFrame(), Frame::ITRF()) ;

    }

    {

        const Instant instant = Instant::DateTime(DateTime(2018, 1, 1, 0, 0, 0), Scale::UTC) ;
        const Position position = Position::Meters({ 1.2, 3.4, 5.6 }, Frame::GCRF()) ;
        const Velocity velocity = Velocity::MetersPerSecond({ 7.8, 9.0, 1.2 }, Frame::GCRF()) ;

        const State state = { instant, position, velocity } ;

        EXPECT_ANY_THROW(State::Undefined().inFrame(Frame::GCRF())) ;
        EXPECT_ANY_THROW(state.inFrame(Frame::Undefined())) ;

    }

}

TEST (OpenSpaceToolkit_Astrodynamics_Trajectory_State, Undefined)
{

    using ostk::astro::trajectory::State ;

    {

        EXPECT_NO_THROW(State::Undefined()) ;

    }

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
