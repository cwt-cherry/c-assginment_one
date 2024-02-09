// Assignment 1 - The Bohr Atom

// Program to calculate transition energy using simple Bohr formula

#include<iostream>
#include<iomanip>
#include <cmath>
using std::string;
// Declare variables
  int atomic_number;
  int initial_quantum_number;
  int final_quantum_number;
  float answer;
  char unit_choice;
  string unit;

// Define function to compute photon energy, Delta E = 13.6*(Z^2)*(1/n_j^2-1/n_i^2) eV
  float photon_energy(int atomic_number, int initial_quantum_number, int final_quantum_number)
  {
    return 13.6 * pow(atomic_number,2) * ( 1/pow(final_quantum_number,2) - 1/pow(initial_quantum_number,2) );
  }

// Main function
  int main()
  {

  // Use while loop to ask user to re-enter input if input data type do not match declared data type
    while(true)
    {
    // Ask user to enter atomic number, initial quantum number and final quantum number
      std::cout<<"Enter atomic number: "<<std::endl<<"Enter initial quantum number: "<<std::endl<<"Enter final quantum number: "<<std::endl;
        
        if(std::cin>>atomic_number>>initial_quantum_number>>final_quantum_number)
        {
        // Exit loop if input matches declared data type
          break;
        }
        else
        {
        // Reset error state of the input stream
          std::cin.clear();
        // Discard any remaining characters in the input buffer
          std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
          std::cout<<"Invalid input. Please enter a numeric value."<<std::endl;
        }

    }
  // Ask user to choose the unit of energy
    std::cout<<"Convert energy unit from eV to J? (y/n)";
    std::cin>>unit_choice;

  // Use if statement for unit conversion and printing output
    if(unit_choice == 'y')
    {
      unit = "J";
      answer = photon_energy(atomic_number, initial_quantum_number,final_quantum_number) / 1.6e-19;
      std::cout<<"Transition energy is "<<answer<<unit;
    }
    else if(unit_choice == 'n')
    {
      unit = "eV";
      answer = photon_energy(atomic_number, initial_quantum_number,final_quantum_number);
      std::cout<<"Transition energy is "<<answer<<unit;
    }
    else
    {
      std::cout<<"Answer is expressed in eV as preferred unit is not selected."<<std::endl;
      unit = "eV";
      answer = photon_energy(atomic_number, initial_quantum_number,final_quantum_number);
      std::cout<<"Transition energy is "<<answer<<unit;
    }

  // Execute main function
    return 0;
  }