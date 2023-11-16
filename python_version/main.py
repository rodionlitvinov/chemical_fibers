import csv


class Fiber:
    def __init__(self, burns_quickly, dissolves_in_acetone, threads_extractable, shrinks_when_burned, name):
        self.burns_quickly = burns_quickly
        self.dissolves_in_acetone = dissolves_in_acetone
        self.threads_extractable = threads_extractable
        self.shrinks_when_burned = shrinks_when_burned
        self.name = name

    @staticmethod
    def identify_fiber(fibers, properties):
        potential_fibers = fibers
        for prop, value in properties.items():
            if value is not None:
                potential_fibers = [fiber for fiber in potential_fibers if getattr(fiber, prop) == value]

        if len(potential_fibers) == 1:
            return potential_fibers[0].name
        elif not potential_fibers:
            return 'Unknown'
        else:
            print("Multiple fibers match the criteria:")
            for fiber in potential_fibers:
                print(fiber.name)
            return 'Multiple matches found, please provide more details.'


def get_user_input(question):
    while True:
        response = input(question).strip().lower()
        if response in ['yes', 'y', 'YES', 'Yes']:
            return True
        elif response in ['no', 'n', 'NO', 'No']:
            return False
        else:
            print("Invalid input. Please answer with 'yes' or 'no'.")


def ask_user():
    print("Please answer the following questions with 'yes' or 'no'.")

    burns_quickly = get_user_input("Does the fiber burn quickly? ")
    dissolves_in_acetone = get_user_input("Does the fiber dissolve in acetone? ")
    threads_extractable = get_user_input("Can threads be extracted from the resin? ")
    shrinks_when_burned = get_user_input("Does the fiber shrink when burned? ")

    return {
        'burns_quickly': burns_quickly,
        'dissolves_in_acetone': dissolves_in_acetone,
        'threads_extractable': threads_extractable,
        'shrinks_when_burned': shrinks_when_burned
    }


def string_to_bool(s):
    return s.strip().lower() == 'yes'


def load_fibers_from_csv(filepath):
    with open(filepath, mode='r', newline='') as file:
        reader = csv.DictReader(file)
        return [Fiber(
            string_to_bool(fiber['burns_quickly']),
            string_to_bool(fiber['dissolves_in_acetone']),
            string_to_bool(fiber['threads_extractable']),
            string_to_bool(fiber['shrinks_when_burned']),
            fiber['name'].strip()
        ) for fiber in reader]


def save_fibers_to_csv(fibers, filepath):
    with open(filepath, mode='w', newline='') as file:
        fieldnames = ['burns_quickly', 'dissolves_in_acetone', 'threads_extractable', 'shrinks_when_burned', 'name']
        writer = csv.DictWriter(file, fieldnames=fieldnames)

        writer.writeheader()
        for fiber in fibers:
            writer.writerow({
                'burns_quickly': 'Yes' if fiber.burns_quickly else 'No',
                'dissolves_in_acetone': 'Yes' if fiber.dissolves_in_acetone else 'No',
                'threads_extractable': 'Yes' if fiber.threads_extractable else 'No',
                'shrinks_when_burned': 'Yes' if fiber.shrinks_when_burned else 'No',
                'name': fiber.name
            })


def add_new_fiber(fibers):
    name = input("Enter the name of the new fiber: ").strip()
    burns_quickly = get_user_input("Does the fiber burn quickly? (Yes/No) ")
    dissolves_in_acetone = get_user_input("Does the fiber dissolve in acetone? (Yes/No) ")
    threads_extractable = get_user_input("Can threads be extracted from the resin? (Yes/No) ")
    shrinks_when_burned = get_user_input("Does the fiber shrink when burned? (Yes/No) ")

    new_fiber = Fiber(burns_quickly, dissolves_in_acetone, threads_extractable, shrinks_when_burned, name)
    fibers.append(new_fiber)
    save_fibers_to_csv(fibers, 'fibers.csv')


def select_and_view_fiber(fibers):
    print("\nSelect a fiber to view information:")
    for i, fiber in enumerate(fibers, 1):
        print(f"{i}. {fiber.name}")

    choice = int(input("Enter the number of the fiber: "))
    if 1 <= choice <= len(fibers):
        fiber = fibers[choice - 1]
        print(f"Name: {fiber.name}")
        print(f"Burns Quickly: {'Yes' if fiber.burns_quickly else 'No'}")
        print(f"Dissolves in Acetone: {'Yes' if fiber.dissolves_in_acetone else 'No'}")
        print(f"Threads Extractable: {'Yes' if fiber.threads_extractable else 'No'}")
        print(f"Shrinks When Burned: {'Yes' if fiber.shrinks_when_burned else 'No'}")
    else:
        print("Invalid selection.")


def view_all_fibers(fibers):
    print("\nProperties of all fibers:")
    for fiber in fibers:
        print(f"Name: {fiber.name}")
        print(f"Burns Quickly: {'Yes' if fiber.burns_quickly else 'No'}")
        print(f"Dissolves in Acetone: {'Yes' if fiber.dissolves_in_acetone else 'No'}")
        print(f"Threads Extractable: {'Yes' if fiber.threads_extractable else 'No'}")
        print(f"Shrinks When Burned: {'Yes' if fiber.shrinks_when_burned else 'No'}\n")


def how_to_use():
    print("""
    To use the application:
    - Choose an option from the main menu by entering the number next to the option.
    - Follow the prompts provided by the application.
    - Enter 'yes' or 'no' when asked about fiber properties.
    - To exit, choose the 'Exit' option from the main menu.
    """)


def program_info():
    print("""
    Fiber Buddy
    Version: 1.0
    Author: Radion Litvinov
    License: Freeware
    """)


def print_menu():
    print("""
    Main Menu:
    1. Identify fiber by its physical properties
    2. Select and view information about a fiber
    3. How to use the application
    4. Information about the program
    5. View properties of all fibers
    6. Add a new fiber
    7. Exit
    """)


def main():
    print("""
    ==========================
        Fibers Buddy v1.0
    ==========================
    """)
    fibers = load_fibers_from_csv('fibers.csv')
    while True:
        print_menu()
        choice = input("Enter your choice: ").strip()

        if choice == '1':
            properties = ask_user()
            fiber_name = Fiber.identify_fiber(fibers, properties)
            print(f"\nThe identified fiber is: \n==================\n{fiber_name}\n==================")
        elif choice == '2':
            select_and_view_fiber(fibers)
        elif choice == '3':
            how_to_use()
        elif choice == '4':
            program_info()
        elif choice == '5':
            view_all_fibers(fibers)
        elif choice == '6':
            add_new_fiber(fibers)
        elif choice == '7':
            print("Exiting the program.")
            break
        else:
            print("Invalid selection, please try again.")

        input("Press Enter to return to the main menu...")


if __name__ == "__main__":
    main()
