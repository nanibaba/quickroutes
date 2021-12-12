cmake_minimum_required(VERSION 3.20)
project(QuickRoutes)

set(CMAKE_CXX_STANDARD 14)

add_executable(QuickRoutes main.cpp Product.h Complaint.h Truck.h Van.h Route.h Delivery.h Employee.h Administrator.h Driver.h SuperAdmin.h Manager.h Clerk.h TruckDriver.h VanDriver.h Supervisor.h)
