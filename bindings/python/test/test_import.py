################################################################################################################################################################

# @project        Open Space Toolkit ▸ Astrodynamics
# @file           bindings/python/test/test_import.py
# @author         Lucas Brémond <lucas@loftorbital.com>
# @license        Apache License 2.0

################################################################################################################################################################

import pytest

################################################################################################################################################################

class TestImport:

    def test_import (self):

        from ostk.astrodynamics import Trajectory
        from ostk.astrodynamics.trajectory import State
        from ostk.astrodynamics.trajectory import Orbit
        from ostk.astrodynamics.trajectory import Model
        from ostk.astrodynamics.trajectory.orbit import Pass
        from ostk.astrodynamics.trajectory.orbit.models import Kepler
        from ostk.astrodynamics.trajectory.orbit.models.kepler import COE
        from ostk.astrodynamics.trajectory.orbit.models import SGP4
        from ostk.astrodynamics.trajectory.orbit.models.sgp4 import TLE
        from ostk.astrodynamics.trajectory.orbit.models import Propagated
        from ostk.astrodynamics.flight import Profile
        from ostk.astrodynamics.flight import System
        from ostk.astrodynamics.flight.system import SatelliteSystem
        from ostk.astrodynamics.flight.system.dynamics import SatelliteDynamics
        from ostk.astrodynamics import Access
        from ostk.astrodynamics.access import Generator
        from ostk.astrodynamics import NumericalSolver

################################################################################################################################################################
