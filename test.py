import os

# Function to rename all files in a folder by adding a prefix
def rename_files_in_folder(folder_path, prefix):
    # Loop through all the files in the folder
    for filename in os.listdir(folder_path):
        # Get the file extension and original name without extension
        file_name, file_extension = os.path.splitext(filename)
        
        # Create new filename with the prefix
        new_filename = f"{prefix}{file_name}{file_extension}"
        
        # Original file path
        original_path = os.path.join(folder_path, filename)
        # New file path
        new_file_path = os.path.join(folder_path, new_filename)

        # Renaming the file
        os.rename(original_path, new_file_path)
        print(f"Renamed: {filename} -> {new_filename}")

# Folder path where the files are located
folder_path = "C:\\Users\\BIT\\Desktop\\Dataset\\unlabbelled\\aim_images\\turn_left\\images"

# Call the function to add the prefix
rename_files_in_folder(folder_path, prefix="turn_left_")
