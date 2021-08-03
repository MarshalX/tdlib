#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <sstream>

#include <pybind11/pybind11.h>

#include <td/telegram/td_api.h>
#include <td/tl/TlObject.h>


template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

namespace py = pybind11;
namespace td_api = td::td_api;


void ping() {


    py::print("pong");
}

PYBIND11_DECLARE_HOLDER_TYPE(Type, td_api::object_ptr<Type>)
PYBIND11_MODULE(tdlib_native, m) {
    m.def("ping", &ping);

    py::register_exception_translator([](std::exception_ptr p) {
        try {
            if (p) std::rethrow_exception(p);
        } catch (const std::exception &e) {
            PyErr_SetString(PyExc_RuntimeError, e.what());
        }
    });

    // --Base Classes--

    py::class_<td::TlObject>(m, "TlObject");
    py::class_<td_api::Object>(m, "Object");
    py::class_<td_api::Function>(m, "Function");

    // ---Abstract Classes---
    
    // Provides information about the method by which an authentication code is delivered to the user
    py::class_<td_api::AuthenticationCodeType>(m, "AuthenticationCodeType");

    // Represents the current authorization state of the TDLib client
    py::class_<td_api::AuthorizationState>(m, "AuthorizationState");

    // Points to a file
    py::class_<td_api::InputFile>(m, "InputFile");

    // Describes format of the thumbnail
    py::class_<td_api::ThumbnailFormat>(m, "ThumbnailFormat");

    // Part of the face, relative to which a mask should be placed
    py::class_<td_api::MaskPoint>(m, "MaskPoint");

    // Describes the type of a poll
    py::class_<td_api::PollType>(m, "PollType");

    // Represents the type of a user. The following types are possible: regular users, deleted users and bots
    py::class_<td_api::UserType>(m, "UserType");

    // Describes a photo to be set as a user profile or chat photo
    py::class_<td_api::InputChatPhoto>(m, "InputChatPhoto");

    // Provides information about the status of a member in a chat
    py::class_<td_api::ChatMemberStatus>(m, "ChatMemberStatus");

    // Specifies the kind of chat members to return in searchChatMembers
    py::class_<td_api::ChatMembersFilter>(m, "ChatMembersFilter");

    // Specifies the kind of chat members to return in getSupergroupMembers
    py::class_<td_api::SupergroupMembersFilter>(m, "SupergroupMembersFilter");

    // Describes the current secret chat state
    py::class_<td_api::SecretChatState>(m, "SecretChatState");

    // Contains information about the sender of a message
    py::class_<td_api::MessageSender>(m, "MessageSender");

    // Contains information about the origin of a forwarded message
    py::class_<td_api::MessageForwardOrigin>(m, "MessageForwardOrigin");

    // Contains information about the sending state of the message
    py::class_<td_api::MessageSendingState>(m, "MessageSendingState");

    // Describes the types of chats to which notification settings are relevant
    py::class_<td_api::NotificationSettingsScope>(m, "NotificationSettingsScope");

    // Describes the type of a chat
    py::class_<td_api::ChatType>(m, "ChatType");

    // Describes a list of chats
    py::class_<td_api::ChatList>(m, "ChatList");

    // Describes a reason why an external chat is shown in a chat list
    py::class_<td_api::ChatSource>(m, "ChatSource");

    // Describes a type of public chats
    py::class_<td_api::PublicChatType>(m, "PublicChatType");

    // Describes actions which should be possible to do through a chat action bar
    py::class_<td_api::ChatActionBar>(m, "ChatActionBar");

    // Describes a keyboard button type
    py::class_<td_api::KeyboardButtonType>(m, "KeyboardButtonType");

    // Describes the type of an inline keyboard button
    py::class_<td_api::InlineKeyboardButtonType>(m, "InlineKeyboardButtonType");

    // Contains a description of a custom keyboard and actions that can be done with it to quickly reply to bots
    py::class_<td_api::ReplyMarkup>(m, "ReplyMarkup");

    // Contains information about an inline button of type inlineKeyboardButtonTypeLoginUrl
    py::class_<td_api::LoginUrlInfo>(m, "LoginUrlInfo");

    // Describes a text object inside an instant-view web page
    py::class_<td_api::RichText>(m, "RichText");

    // Describes a horizontal alignment of a table cell content
    py::class_<td_api::PageBlockHorizontalAlignment>(m, "PageBlockHorizontalAlignment");

    // Describes a Vertical alignment of a table cell content
    py::class_<td_api::PageBlockVerticalAlignment>(m, "PageBlockVerticalAlignment");

    // Describes a block of an instant view web page
    py::class_<td_api::PageBlock>(m, "PageBlock");

    // Contains information about the payment method chosen by the user
    py::class_<td_api::InputCredentials>(m, "InputCredentials");

    // Contains the type of a Telegram Passport element
    py::class_<td_api::PassportElementType>(m, "PassportElementType");

    // Contains information about a Telegram Passport element
    py::class_<td_api::PassportElement>(m, "PassportElement");

    // Contains information about a Telegram Passport element to be saved
    py::class_<td_api::InputPassportElement>(m, "InputPassportElement");

    // Contains the description of an error in a Telegram Passport element
    py::class_<td_api::PassportElementErrorSource>(m, "PassportElementErrorSource");

    // Contains the description of an error in a Telegram Passport element; for bots only
    py::class_<td_api::InputPassportElementErrorSource>(m, "InputPassportElementErrorSource");

    // Contains the content of a message
    py::class_<td_api::MessageContent>(m, "MessageContent");

    // Represents a part of the text which must be formatted differently
    py::class_<td_api::TextEntityType>(m, "TextEntityType");

    // Contains information about the time when a scheduled message will be sent
    py::class_<td_api::MessageSchedulingState>(m, "MessageSchedulingState");

    // The content of a message to send
    py::class_<td_api::InputMessageContent>(m, "InputMessageContent");

    // Represents a filter for message search results
    py::class_<td_api::SearchMessagesFilter>(m, "SearchMessagesFilter");

    // Describes the different types of activity in a chat
    py::class_<td_api::ChatAction>(m, "ChatAction");

    // Describes the last time the user was online
    py::class_<td_api::UserStatus>(m, "UserStatus");

    // Describes the reason why a call was discarded
    py::class_<td_api::CallDiscardReason>(m, "CallDiscardReason");

    // Describes the type of a call server
    py::class_<td_api::CallServerType>(m, "CallServerType");

    // Describes the current call state
    py::class_<td_api::CallState>(m, "CallState");

    // Describes the exact type of a problem with a call
    py::class_<td_api::CallProblem>(m, "CallProblem");

    // Contains animated stickers which should be used for dice animation rendering
    py::class_<td_api::DiceStickers>(m, "DiceStickers");

    // Represents a single result of an inline query; for bots only
    py::class_<td_api::InputInlineQueryResult>(m, "InputInlineQueryResult");

    // Represents a single result of an inline query
    py::class_<td_api::InlineQueryResult>(m, "InlineQueryResult");

    // Represents a payload of a callback query
    py::class_<td_api::CallbackQueryPayload>(m, "CallbackQueryPayload");

    // Represents a chat event
    py::class_<td_api::ChatEventAction>(m, "ChatEventAction");

    // Represents the value of a string in a language pack
    py::class_<td_api::LanguagePackStringValue>(m, "LanguagePackStringValue");

    // Represents a data needed to subscribe for push notifications through registerDevice method. To use specific push notification service, the correct application platform must be specified and a valid server authentication data must be uploaded at https://my.telegram.org
    py::class_<td_api::DeviceToken>(m, "DeviceToken");

    // Describes a fill of a background
    py::class_<td_api::BackgroundFill>(m, "BackgroundFill");

    // Describes the type of a background
    py::class_<td_api::BackgroundType>(m, "BackgroundType");

    // Contains information about background to set
    py::class_<td_api::InputBackground>(m, "InputBackground");

    // Represents result of checking whether the current session can be used to transfer a chat ownership to another user
    py::class_<td_api::CanTransferOwnershipResult>(m, "CanTransferOwnershipResult");

    // Represents result of checking whether a username can be set for a chat
    py::class_<td_api::CheckChatUsernameResult>(m, "CheckChatUsernameResult");

    // Represents result of checking whether a name can be used for a new sticker set
    py::class_<td_api::CheckStickerSetNameResult>(m, "CheckStickerSetNameResult");

    // Represents result of 2-step verification password reset
    py::class_<td_api::ResetPasswordResult>(m, "ResetPasswordResult");

    // Contains information about a file with messages exported from another app
    py::class_<td_api::MessageFileType>(m, "MessageFileType");

    // Contains content of a push message notification
    py::class_<td_api::PushMessageContent>(m, "PushMessageContent");

    // Contains detailed information about a notification
    py::class_<td_api::NotificationType>(m, "NotificationType");

    // Describes the type of notifications in a notification group
    py::class_<td_api::NotificationGroupType>(m, "NotificationGroupType");

    // Represents the value of an option
    py::class_<td_api::OptionValue>(m, "OptionValue");

    // Represents a JSON value
    py::class_<td_api::JsonValue>(m, "JsonValue");

    // Represents a single rule for managing privacy settings
    py::class_<td_api::UserPrivacySettingRule>(m, "UserPrivacySettingRule");

    // Describes available user privacy settings
    py::class_<td_api::UserPrivacySetting>(m, "UserPrivacySetting");

    // Describes the reason why a chat is reported
    py::class_<td_api::ChatReportReason>(m, "ChatReportReason");

    // Describes an internal https://t.me or tg: link, which must be processed by the app in a special way
    py::class_<td_api::InternalLinkType>(m, "InternalLinkType");

    // Represents the type of a file
    py::class_<td_api::FileType>(m, "FileType");

    // Represents the type of a network
    py::class_<td_api::NetworkType>(m, "NetworkType");

    // Contains statistics about network usage
    py::class_<td_api::NetworkStatisticsEntry>(m, "NetworkStatisticsEntry");

    // Describes the current state of the connection to Telegram servers
    py::class_<td_api::ConnectionState>(m, "ConnectionState");

    // Represents the categories of chats for which a list of frequently used chats can be retrieved
    py::class_<td_api::TopChatCategory>(m, "TopChatCategory");

    // Describes the type of a URL linking to an internal Telegram entity
    py::class_<td_api::TMeUrlType>(m, "TMeUrlType");

    // Describes an action suggested to the current user
    py::class_<td_api::SuggestedAction>(m, "SuggestedAction");

    // Describes the way the text should be parsed for TextEntities
    py::class_<td_api::TextParseMode>(m, "TextParseMode");

    // Describes the type of a proxy server
    py::class_<td_api::ProxyType>(m, "ProxyType");

    // Describes a sticker that needs to be added to a sticker set
    py::class_<td_api::InputSticker>(m, "InputSticker");

    // Describes a statistical graph
    py::class_<td_api::StatisticalGraph>(m, "StatisticalGraph");

    // Contains a detailed statistics about a chat
    py::class_<td_api::ChatStatistics>(m, "ChatStatistics");

    // Represents a vector path command
    py::class_<td_api::VectorPathCommand>(m, "VectorPathCommand");

    // Represents the scope to which bot commands are relevant
    py::class_<td_api::BotCommandScope>(m, "BotCommandScope");

    // Contains notifications about data changes
    py::class_<td_api::Update>(m, "Update");

    // Describes a stream to which TDLib internal log is written
    py::class_<td_api::LogStream>(m, "LogStream");

    // --Classes--
    
    // An object of this type can be returned on every function call, in case of an error
    py::class_<td_api::error>(m, "error")
            .def(py::init<>())
    
            .def_readwrite("code", &td_api::error::code_)
            .def_readwrite("message", &td_api::error::message_);
    
    // An object of this type is returned on a successful function call for certain functions
    py::class_<td_api::ok>(m, "ok")
            .def(py::init<>());
    
    // Contains parameters for TDLib initialization
    py::class_<td_api::tdlibParameters>(m, "tdlibParameters")
            .def(py::init<>())
    
            .def_readwrite("use_test_dc", &td_api::tdlibParameters::use_test_dc_)
            .def_readwrite("database_directory", &td_api::tdlibParameters::database_directory_)
            .def_readwrite("files_directory", &td_api::tdlibParameters::files_directory_)
            .def_readwrite("use_file_database", &td_api::tdlibParameters::use_file_database_)
            .def_readwrite("use_chat_info_database", &td_api::tdlibParameters::use_chat_info_database_)
            .def_readwrite("use_message_database", &td_api::tdlibParameters::use_message_database_)
            .def_readwrite("use_secret_chats", &td_api::tdlibParameters::use_secret_chats_)
            .def_readwrite("api_id", &td_api::tdlibParameters::api_id_)
            .def_readwrite("api_hash", &td_api::tdlibParameters::api_hash_)
            .def_readwrite("system_language_code", &td_api::tdlibParameters::system_language_code_)
            .def_readwrite("device_model", &td_api::tdlibParameters::device_model_)
            .def_readwrite("system_version", &td_api::tdlibParameters::system_version_)
            .def_readwrite("application_version", &td_api::tdlibParameters::application_version_)
            .def_readwrite("enable_storage_optimizer", &td_api::tdlibParameters::enable_storage_optimizer_)
            .def_readwrite("ignore_file_names", &td_api::tdlibParameters::ignore_file_names_);
    
    // An authentication code is delivered via a private Telegram message, which can be viewed from another active session @length Length of the code
    py::class_<td_api::authenticationCodeTypeTelegramMessage>(m, "authenticationCodeTypeTelegramMessage")
            .def(py::init<>())
    
            .def_readwrite("length", &td_api::authenticationCodeTypeTelegramMessage::length_);
    
    // An authentication code is delivered via an SMS message to the specified phone number @length Length of the code
    py::class_<td_api::authenticationCodeTypeSms>(m, "authenticationCodeTypeSms")
            .def(py::init<>())
    
            .def_readwrite("length", &td_api::authenticationCodeTypeSms::length_);
    
    // An authentication code is delivered via a phone call to the specified phone number @length Length of the code
    py::class_<td_api::authenticationCodeTypeCall>(m, "authenticationCodeTypeCall")
            .def(py::init<>())
    
            .def_readwrite("length", &td_api::authenticationCodeTypeCall::length_);
    
    // An authentication code is delivered by an immediately canceled call to the specified phone number. The number from which the call was made is the code @pattern Pattern of the phone number from which the call will be made
    py::class_<td_api::authenticationCodeTypeFlashCall>(m, "authenticationCodeTypeFlashCall")
            .def(py::init<>())
    
            .def_readwrite("pattern", &td_api::authenticationCodeTypeFlashCall::pattern_);
    
    // Information about the authentication code that was sent @phone_number A phone number that is being authenticated @type Describes the way the code was sent to the user @next_type Describes the way the next code will be sent to the user; may be null @timeout Timeout before the code can be re-sent, in seconds
    py::class_<td_api::authenticationCodeInfo>(m, "authenticationCodeInfo")
            .def(py::init<>())
    
            .def_readwrite("phone_number", &td_api::authenticationCodeInfo::phone_number_)
            .def_readwrite("type", &td_api::authenticationCodeInfo::type_)
            .def_readwrite("next_type", &td_api::authenticationCodeInfo::next_type_)
            .def_readwrite("timeout", &td_api::authenticationCodeInfo::timeout_);
    
    // Information about the email address authentication code that was sent @email_address_pattern Pattern of the email address to which an authentication code was sent @length Length of the code; 0 if unknown
    py::class_<td_api::emailAddressAuthenticationCodeInfo>(m, "emailAddressAuthenticationCodeInfo")
            .def(py::init<>())
    
            .def_readwrite("email_address_pattern", &td_api::emailAddressAuthenticationCodeInfo::email_address_pattern_)
            .def_readwrite("length", &td_api::emailAddressAuthenticationCodeInfo::length_);
    
    // Represents a part of the text that needs to be formatted in some unusual way @offset Offset of the entity, in UTF-16 code units @length Length of the entity, in UTF-16 code units @type Type of the entity
    py::class_<td_api::textEntity>(m, "textEntity")
            .def(py::init<>())
    
            .def_readwrite("offset", &td_api::textEntity::offset_)
            .def_readwrite("length", &td_api::textEntity::length_)
            .def_readwrite("type", &td_api::textEntity::type_);
    
    // Contains a list of text entities @entities List of text entities
    py::class_<td_api::textEntities>(m, "textEntities")
            .def(py::init<>())
    
            .def_readwrite("entities", &td_api::textEntities::entities_);
    
    // A text with some entities @text The text @entities Entities contained in the text. Entities can be nested, but must not mutually intersect with each other. Pre, Code and PreCode entities can't contain other entities. Bold, Italic, Underline and Strikethrough entities can contain and to be contained in all other entities. All other entities can't contain each other
    py::class_<td_api::formattedText>(m, "formattedText")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::formattedText::text_)
            .def_readwrite("entities", &td_api::formattedText::entities_);
    
    // Contains Telegram terms of service @text Text of the terms of service @min_user_age The minimum age of a user to be able to accept the terms; 0 if any @show_popup True, if a blocking popup with terms of service must be shown to the user
    py::class_<td_api::termsOfService>(m, "termsOfService")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::termsOfService::text_)
            .def_readwrite("min_user_age", &td_api::termsOfService::min_user_age_)
            .def_readwrite("show_popup", &td_api::termsOfService::show_popup_);
    
    // TDLib needs TdlibParameters for initialization
    py::class_<td_api::authorizationStateWaitTdlibParameters>(m, "authorizationStateWaitTdlibParameters")
            .def(py::init<>());
    
    // TDLib needs an encryption key to decrypt the local database @is_encrypted True, if the database is currently encrypted
    py::class_<td_api::authorizationStateWaitEncryptionKey>(m, "authorizationStateWaitEncryptionKey")
            .def(py::init<>())
    
            .def_readwrite("is_encrypted", &td_api::authorizationStateWaitEncryptionKey::is_encrypted_);
    
    // TDLib needs the user's phone number to authorize. Call `setAuthenticationPhoneNumber` to provide the phone number, or use `requestQrCodeAuthentication`, or `checkAuthenticationBotToken` for other authentication options
    py::class_<td_api::authorizationStateWaitPhoneNumber>(m, "authorizationStateWaitPhoneNumber")
            .def(py::init<>());
    
    // TDLib needs the user's authentication code to authorize @code_info Information about the authorization code that was sent
    py::class_<td_api::authorizationStateWaitCode>(m, "authorizationStateWaitCode")
            .def(py::init<>())
    
            .def_readwrite("code_info", &td_api::authorizationStateWaitCode::code_info_);
    
    // The user needs to confirm authorization on another logged in device by scanning a QR code with the provided link @link A tg:// URL for the QR code. The link will be updated frequently
    py::class_<td_api::authorizationStateWaitOtherDeviceConfirmation>(m, "authorizationStateWaitOtherDeviceConfirmation")
            .def(py::init<>())
    
            .def_readwrite("link", &td_api::authorizationStateWaitOtherDeviceConfirmation::link_);
    
    // The user is unregistered and need to accept terms of service and enter their first name and last name to finish registration @terms_of_service Telegram terms of service
    py::class_<td_api::authorizationStateWaitRegistration>(m, "authorizationStateWaitRegistration")
            .def(py::init<>())
    
            .def_readwrite("terms_of_service", &td_api::authorizationStateWaitRegistration::terms_of_service_);
    
    // The user has been authorized, but needs to enter a password to start using the application @password_hint Hint for the password; may be empty @has_recovery_email_address True, if a recovery email address has been set up
    py::class_<td_api::authorizationStateWaitPassword>(m, "authorizationStateWaitPassword")
            .def(py::init<>())
    
            .def_readwrite("password_hint", &td_api::authorizationStateWaitPassword::password_hint_)
            .def_readwrite("has_recovery_email_address", &td_api::authorizationStateWaitPassword::has_recovery_email_address_)
            .def_readwrite("recovery_email_address_pattern", &td_api::authorizationStateWaitPassword::recovery_email_address_pattern_);
    
    // The user has been successfully authorized. TDLib is now ready to answer queries
    py::class_<td_api::authorizationStateReady>(m, "authorizationStateReady")
            .def(py::init<>());
    
    // The user is currently logging out
    py::class_<td_api::authorizationStateLoggingOut>(m, "authorizationStateLoggingOut")
            .def(py::init<>());
    
    // TDLib is closing, all subsequent queries will be answered with the error 500. Note that closing TDLib can take a while. All resources will be freed only after authorizationStateClosed has been received
    py::class_<td_api::authorizationStateClosing>(m, "authorizationStateClosing")
            .def(py::init<>());
    
    // TDLib client is in its final state. All databases are closed and all resources are released. No other updates will be received after this. All queries will be responded to with error code 500. To continue working, one should create a new instance of the TDLib client
    py::class_<td_api::authorizationStateClosed>(m, "authorizationStateClosed")
            .def(py::init<>());
    
    // Represents the current state of 2-step verification @has_password True, if a 2-step verification password is set @password_hint Hint for the password; may be empty
    py::class_<td_api::passwordState>(m, "passwordState")
            .def(py::init<>())
    
            .def_readwrite("has_password", &td_api::passwordState::has_password_)
            .def_readwrite("password_hint", &td_api::passwordState::password_hint_)
            .def_readwrite("has_recovery_email_address", &td_api::passwordState::has_recovery_email_address_)
            .def_readwrite("has_passport_data", &td_api::passwordState::has_passport_data_)
            .def_readwrite("recovery_email_address_code_info", &td_api::passwordState::recovery_email_address_code_info_)
            .def_readwrite("pending_reset_date", &td_api::passwordState::pending_reset_date_);
    
    // Contains information about the current recovery email address @recovery_email_address Recovery email address
    py::class_<td_api::recoveryEmailAddress>(m, "recoveryEmailAddress")
            .def(py::init<>())
    
            .def_readwrite("recovery_email_address", &td_api::recoveryEmailAddress::recovery_email_address_);
    
    // Returns information about the availability of a temporary password, which can be used for payments @has_password True, if a temporary password is available @valid_for Time left before the temporary password expires, in seconds
    py::class_<td_api::temporaryPasswordState>(m, "temporaryPasswordState")
            .def(py::init<>())
    
            .def_readwrite("has_password", &td_api::temporaryPasswordState::has_password_)
            .def_readwrite("valid_for", &td_api::temporaryPasswordState::valid_for_);
    
    // Represents a local file
    py::class_<td_api::localFile>(m, "localFile")
            .def(py::init<>())
    
            .def_readwrite("path", &td_api::localFile::path_)
            .def_readwrite("can_be_downloaded", &td_api::localFile::can_be_downloaded_)
            .def_readwrite("can_be_deleted", &td_api::localFile::can_be_deleted_)
            .def_readwrite("is_downloading_active", &td_api::localFile::is_downloading_active_)
            .def_readwrite("is_downloading_completed", &td_api::localFile::is_downloading_completed_)
            .def_readwrite("download_offset", &td_api::localFile::download_offset_)
            .def_readwrite("downloaded_prefix_size", &td_api::localFile::downloaded_prefix_size_)
            .def_readwrite("downloaded_size", &td_api::localFile::downloaded_size_);
    
    // Represents a remote file
    py::class_<td_api::remoteFile>(m, "remoteFile")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::remoteFile::id_)
            .def_readwrite("unique_id", &td_api::remoteFile::unique_id_)
            .def_readwrite("is_uploading_active", &td_api::remoteFile::is_uploading_active_)
            .def_readwrite("is_uploading_completed", &td_api::remoteFile::is_uploading_completed_)
            .def_readwrite("uploaded_size", &td_api::remoteFile::uploaded_size_);
    
    // Represents a file
    py::class_<td_api::file>(m, "file")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::file::id_)
            .def_readwrite("size", &td_api::file::size_)
            .def_readwrite("expected_size", &td_api::file::expected_size_)
            .def_readwrite("local", &td_api::file::local_)
            .def_readwrite("remote", &td_api::file::remote_);
    
    // A file defined by its unique ID @id Unique file identifier
    py::class_<td_api::inputFileId>(m, "inputFileId")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputFileId::id_);
    
    // A file defined by its remote ID. The remote ID is guaranteed to be usable only if the corresponding file is still accessible to the user and known to TDLib. For example, if the file is from a message, then the message must be not deleted and accessible to the user. If the file database is disabled, then the corresponding object with the file must be preloaded by the application
    py::class_<td_api::inputFileRemote>(m, "inputFileRemote")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputFileRemote::id_);
    
    // A file defined by a local path @path Local path to the file
    py::class_<td_api::inputFileLocal>(m, "inputFileLocal")
            .def(py::init<>())
    
            .def_readwrite("path", &td_api::inputFileLocal::path_);
    
    // A file generated by the application @original_path Local path to a file from which the file is generated; may be empty if there is no such file
    py::class_<td_api::inputFileGenerated>(m, "inputFileGenerated")
            .def(py::init<>())
    
            .def_readwrite("original_path", &td_api::inputFileGenerated::original_path_)
            .def_readwrite("conversion", &td_api::inputFileGenerated::conversion_)
            .def_readwrite("expected_size", &td_api::inputFileGenerated::expected_size_);
    
    // Describes an image in JPEG format @type Image type (see https://core.telegram.org/constructor/photoSize)
    py::class_<td_api::photoSize>(m, "photoSize")
            .def(py::init<>())
    
            .def_readwrite("type", &td_api::photoSize::type_)
            .def_readwrite("photo", &td_api::photoSize::photo_)
            .def_readwrite("width", &td_api::photoSize::width_)
            .def_readwrite("height", &td_api::photoSize::height_)
            .def_readwrite("progressive_sizes", &td_api::photoSize::progressive_sizes_);
    
    // Thumbnail image of a very poor quality and low resolution @width Thumbnail width, usually doesn't exceed 40 @height Thumbnail height, usually doesn't exceed 40 @data The thumbnail in JPEG format
    py::class_<td_api::minithumbnail>(m, "minithumbnail")
            .def(py::init<>())
    
            .def_readwrite("width", &td_api::minithumbnail::width_)
            .def_readwrite("height", &td_api::minithumbnail::height_)
            .def_readwrite("data", &td_api::minithumbnail::data_);
    
    // The thumbnail is in JPEG format
    py::class_<td_api::thumbnailFormatJpeg>(m, "thumbnailFormatJpeg")
            .def(py::init<>());
    
    // The thumbnail is in PNG format. It will be used only for background patterns
    py::class_<td_api::thumbnailFormatPng>(m, "thumbnailFormatPng")
            .def(py::init<>());
    
    // The thumbnail is in WEBP format. It will be used only for some stickers
    py::class_<td_api::thumbnailFormatWebp>(m, "thumbnailFormatWebp")
            .def(py::init<>());
    
    // The thumbnail is in static GIF format. It will be used only for some bot inline results
    py::class_<td_api::thumbnailFormatGif>(m, "thumbnailFormatGif")
            .def(py::init<>());
    
    // The thumbnail is in TGS format. It will be used only for animated sticker sets
    py::class_<td_api::thumbnailFormatTgs>(m, "thumbnailFormatTgs")
            .def(py::init<>());
    
    // The thumbnail is in MPEG4 format. It will be used only for some animations and videos
    py::class_<td_api::thumbnailFormatMpeg4>(m, "thumbnailFormatMpeg4")
            .def(py::init<>());
    
    // Represents a thumbnail @format Thumbnail format @width Thumbnail width @height Thumbnail height @file The thumbnail
    py::class_<td_api::thumbnail>(m, "thumbnail")
            .def(py::init<>())
    
            .def_readwrite("format", &td_api::thumbnail::format_)
            .def_readwrite("width", &td_api::thumbnail::width_)
            .def_readwrite("height", &td_api::thumbnail::height_)
            .def_readwrite("file", &td_api::thumbnail::file_);
    
    // A mask should be placed relatively to the forehead
    py::class_<td_api::maskPointForehead>(m, "maskPointForehead")
            .def(py::init<>());
    
    // A mask should be placed relatively to the eyes
    py::class_<td_api::maskPointEyes>(m, "maskPointEyes")
            .def(py::init<>());
    
    // A mask should be placed relatively to the mouth
    py::class_<td_api::maskPointMouth>(m, "maskPointMouth")
            .def(py::init<>());
    
    // A mask should be placed relatively to the chin
    py::class_<td_api::maskPointChin>(m, "maskPointChin")
            .def(py::init<>());
    
    // Position on a photo where a mask should be placed @point Part of the face, relative to which the mask should be placed
    py::class_<td_api::maskPosition>(m, "maskPosition")
            .def(py::init<>())
    
            .def_readwrite("point", &td_api::maskPosition::point_)
            .def_readwrite("x_shift", &td_api::maskPosition::x_shift_)
            .def_readwrite("y_shift", &td_api::maskPosition::y_shift_)
            .def_readwrite("scale", &td_api::maskPosition::scale_);
    
    // Represents a closed vector path. The path begins at the end point of the last command @commands List of vector path commands
    py::class_<td_api::closedVectorPath>(m, "closedVectorPath")
            .def(py::init<>())
    
            .def_readwrite("commands", &td_api::closedVectorPath::commands_);
    
    // Describes one answer option of a poll @text Option text; 1-100 characters @voter_count Number of voters for this option, available only for closed or voted polls @vote_percentage The percentage of votes for this option; 0-100
    py::class_<td_api::pollOption>(m, "pollOption")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pollOption::text_)
            .def_readwrite("voter_count", &td_api::pollOption::voter_count_)
            .def_readwrite("vote_percentage", &td_api::pollOption::vote_percentage_)
            .def_readwrite("is_chosen", &td_api::pollOption::is_chosen_)
            .def_readwrite("is_being_chosen", &td_api::pollOption::is_being_chosen_);
    
    // A regular poll @allow_multiple_answers True, if multiple answer options can be chosen simultaneously
    py::class_<td_api::pollTypeRegular>(m, "pollTypeRegular")
            .def(py::init<>())
    
            .def_readwrite("allow_multiple_answers", &td_api::pollTypeRegular::allow_multiple_answers_);
    
    // A poll in quiz mode, which has exactly one correct answer option and can be answered only once
    py::class_<td_api::pollTypeQuiz>(m, "pollTypeQuiz")
            .def(py::init<>())
    
            .def_readwrite("correct_option_id", &td_api::pollTypeQuiz::correct_option_id_)
            .def_readwrite("explanation", &td_api::pollTypeQuiz::explanation_);
    
    // Describes an animation file. The animation must be encoded in GIF or MPEG4 format @duration Duration of the animation, in seconds; as defined by the sender @width Width of the animation @height Height of the animation
    py::class_<td_api::animation>(m, "animation")
            .def(py::init<>())
    
            .def_readwrite("duration", &td_api::animation::duration_)
            .def_readwrite("width", &td_api::animation::width_)
            .def_readwrite("height", &td_api::animation::height_)
            .def_readwrite("file_name", &td_api::animation::file_name_)
            .def_readwrite("mime_type", &td_api::animation::mime_type_)
            .def_readwrite("has_stickers", &td_api::animation::has_stickers_)
            .def_readwrite("minithumbnail", &td_api::animation::minithumbnail_)
            .def_readwrite("thumbnail", &td_api::animation::thumbnail_)
            .def_readwrite("animation", &td_api::animation::animation_);
    
    // Describes an audio file. Audio is usually in MP3 or M4A format @duration Duration of the audio, in seconds; as defined by the sender @title Title of the audio; as defined by the sender @performer Performer of the audio; as defined by the sender
    py::class_<td_api::audio>(m, "audio")
            .def(py::init<>())
    
            .def_readwrite("duration", &td_api::audio::duration_)
            .def_readwrite("title", &td_api::audio::title_)
            .def_readwrite("performer", &td_api::audio::performer_)
            .def_readwrite("file_name", &td_api::audio::file_name_)
            .def_readwrite("mime_type", &td_api::audio::mime_type_)
            .def_readwrite("album_cover_minithumbnail", &td_api::audio::album_cover_minithumbnail_)
            .def_readwrite("album_cover_thumbnail", &td_api::audio::album_cover_thumbnail_)
            .def_readwrite("audio", &td_api::audio::audio_);
    
    // Describes a document of any type @file_name Original name of the file; as defined by the sender @mime_type MIME type of the file; as defined by the sender
    py::class_<td_api::document>(m, "document")
            .def(py::init<>())
    
            .def_readwrite("file_name", &td_api::document::file_name_)
            .def_readwrite("mime_type", &td_api::document::mime_type_)
            .def_readwrite("minithumbnail", &td_api::document::minithumbnail_)
            .def_readwrite("thumbnail", &td_api::document::thumbnail_)
            .def_readwrite("document", &td_api::document::document_);
    
    // Describes a photo @has_stickers True, if stickers were added to the photo. The list of corresponding sticker sets can be received using getAttachedStickerSets
    py::class_<td_api::photo>(m, "photo")
            .def(py::init<>())
    
            .def_readwrite("has_stickers", &td_api::photo::has_stickers_)
            .def_readwrite("minithumbnail", &td_api::photo::minithumbnail_)
            .def_readwrite("sizes", &td_api::photo::sizes_);
    
    // Describes a sticker @set_id The identifier of the sticker set to which the sticker belongs; 0 if none @width Sticker width; as defined by the sender @height Sticker height; as defined by the sender
    py::class_<td_api::sticker>(m, "sticker")
            .def(py::init<>())
    
            .def_readwrite("set_id", &td_api::sticker::set_id_)
            .def_readwrite("width", &td_api::sticker::width_)
            .def_readwrite("height", &td_api::sticker::height_)
            .def_readwrite("emoji", &td_api::sticker::emoji_)
            .def_readwrite("is_animated", &td_api::sticker::is_animated_)
            .def_readwrite("is_mask", &td_api::sticker::is_mask_)
            .def_readwrite("mask_position", &td_api::sticker::mask_position_)
            .def_readwrite("outline", &td_api::sticker::outline_)
            .def_readwrite("thumbnail", &td_api::sticker::thumbnail_)
            .def_readwrite("sticker", &td_api::sticker::sticker_);
    
    // Describes a video file @duration Duration of the video, in seconds; as defined by the sender @width Video width; as defined by the sender @height Video height; as defined by the sender
    py::class_<td_api::video>(m, "video")
            .def(py::init<>())
    
            .def_readwrite("duration", &td_api::video::duration_)
            .def_readwrite("width", &td_api::video::width_)
            .def_readwrite("height", &td_api::video::height_)
            .def_readwrite("file_name", &td_api::video::file_name_)
            .def_readwrite("mime_type", &td_api::video::mime_type_)
            .def_readwrite("has_stickers", &td_api::video::has_stickers_)
            .def_readwrite("supports_streaming", &td_api::video::supports_streaming_)
            .def_readwrite("minithumbnail", &td_api::video::minithumbnail_)
            .def_readwrite("thumbnail", &td_api::video::thumbnail_)
            .def_readwrite("video", &td_api::video::video_);
    
    // Describes a video note. The video must be equal in width and height, cropped to a circle, and stored in MPEG4 format @duration Duration of the video, in seconds; as defined by the sender
    py::class_<td_api::videoNote>(m, "videoNote")
            .def(py::init<>())
    
            .def_readwrite("duration", &td_api::videoNote::duration_)
            .def_readwrite("length", &td_api::videoNote::length_)
            .def_readwrite("minithumbnail", &td_api::videoNote::minithumbnail_)
            .def_readwrite("thumbnail", &td_api::videoNote::thumbnail_)
            .def_readwrite("video", &td_api::videoNote::video_);
    
    // Describes a voice note. The voice note must be encoded with the Opus codec, and stored inside an OGG container. Voice notes can have only a single audio channel @duration Duration of the voice note, in seconds; as defined by the sender
    py::class_<td_api::voiceNote>(m, "voiceNote")
            .def(py::init<>())
    
            .def_readwrite("duration", &td_api::voiceNote::duration_)
            .def_readwrite("waveform", &td_api::voiceNote::waveform_)
            .def_readwrite("mime_type", &td_api::voiceNote::mime_type_)
            .def_readwrite("voice", &td_api::voiceNote::voice_);
    
    // Describes a user contact @phone_number Phone number of the user @first_name First name of the user; 1-255 characters in length @last_name Last name of the user @vcard Additional data about the user in a form of vCard; 0-2048 bytes in length @user_id Identifier of the user, if known; otherwise 0
    py::class_<td_api::contact>(m, "contact")
            .def(py::init<>())
    
            .def_readwrite("phone_number", &td_api::contact::phone_number_)
            .def_readwrite("first_name", &td_api::contact::first_name_)
            .def_readwrite("last_name", &td_api::contact::last_name_)
            .def_readwrite("vcard", &td_api::contact::vcard_)
            .def_readwrite("user_id", &td_api::contact::user_id_);
    
    // Describes a location on planet Earth @latitude Latitude of the location in degrees; as defined by the sender @longitude Longitude of the location, in degrees; as defined by the sender
    py::class_<td_api::location>(m, "location")
            .def(py::init<>())
    
            .def_readwrite("latitude", &td_api::location::latitude_)
            .def_readwrite("longitude", &td_api::location::longitude_)
            .def_readwrite("horizontal_accuracy", &td_api::location::horizontal_accuracy_);
    
    // Describes a venue @location Venue location; as defined by the sender @title Venue name; as defined by the sender @address Venue address; as defined by the sender @provider Provider of the venue database; as defined by the sender. Currently only "foursquare" and "gplaces" (Google Places) need to be supported
    py::class_<td_api::venue>(m, "venue")
            .def(py::init<>())
    
            .def_readwrite("location", &td_api::venue::location_)
            .def_readwrite("title", &td_api::venue::title_)
            .def_readwrite("address", &td_api::venue::address_)
            .def_readwrite("provider", &td_api::venue::provider_)
            .def_readwrite("id", &td_api::venue::id_)
            .def_readwrite("type", &td_api::venue::type_);
    
    // Describes a game @id Game ID @short_name Game short name. To share a game use the URL https://t.me/{bot_username}?game={game_short_name} @title Game title @text Game text, usually containing scoreboards for a game
    py::class_<td_api::game>(m, "game")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::game::id_)
            .def_readwrite("short_name", &td_api::game::short_name_)
            .def_readwrite("title", &td_api::game::title_)
            .def_readwrite("text", &td_api::game::text_)
            .def_readwrite("description", &td_api::game::description_)
            .def_readwrite("photo", &td_api::game::photo_)
            .def_readwrite("animation", &td_api::game::animation_);
    
    // Describes a poll @id Unique poll identifier @question Poll question; 1-300 characters @options List of poll answer options
    py::class_<td_api::poll>(m, "poll")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::poll::id_)
            .def_readwrite("question", &td_api::poll::question_)
            .def_readwrite("options", &td_api::poll::options_)
            .def_readwrite("total_voter_count", &td_api::poll::total_voter_count_)
            .def_readwrite("recent_voter_user_ids", &td_api::poll::recent_voter_user_ids_)
            .def_readwrite("is_anonymous", &td_api::poll::is_anonymous_)
            .def_readwrite("type", &td_api::poll::type_)
            .def_readwrite("open_period", &td_api::poll::open_period_)
            .def_readwrite("close_date", &td_api::poll::close_date_)
            .def_readwrite("is_closed", &td_api::poll::is_closed_);
    
    // Describes a user profile photo @id Photo identifier; 0 for an empty photo. Can be used to find a photo in a list of user profile photos
    py::class_<td_api::profilePhoto>(m, "profilePhoto")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::profilePhoto::id_)
            .def_readwrite("small", &td_api::profilePhoto::small_)
            .def_readwrite("big", &td_api::profilePhoto::big_)
            .def_readwrite("minithumbnail", &td_api::profilePhoto::minithumbnail_)
            .def_readwrite("has_animation", &td_api::profilePhoto::has_animation_);
    
    // Contains basic information about the photo of a chat
    py::class_<td_api::chatPhotoInfo>(m, "chatPhotoInfo")
            .def(py::init<>())
    
            .def_readwrite("small", &td_api::chatPhotoInfo::small_)
            .def_readwrite("big", &td_api::chatPhotoInfo::big_)
            .def_readwrite("minithumbnail", &td_api::chatPhotoInfo::minithumbnail_)
            .def_readwrite("has_animation", &td_api::chatPhotoInfo::has_animation_);
    
    // A regular user
    py::class_<td_api::userTypeRegular>(m, "userTypeRegular")
            .def(py::init<>());
    
    // A deleted user or deleted bot. No information on the user besides the user identifier is available. It is not possible to perform any active actions on this type of user
    py::class_<td_api::userTypeDeleted>(m, "userTypeDeleted")
            .def(py::init<>());
    
    // A bot (see https://core.telegram.org/bots) @can_join_groups True, if the bot can be invited to basic group and supergroup chats
    py::class_<td_api::userTypeBot>(m, "userTypeBot")
            .def(py::init<>())
    
            .def_readwrite("can_join_groups", &td_api::userTypeBot::can_join_groups_)
            .def_readwrite("can_read_all_group_messages", &td_api::userTypeBot::can_read_all_group_messages_)
            .def_readwrite("is_inline", &td_api::userTypeBot::is_inline_)
            .def_readwrite("inline_query_placeholder", &td_api::userTypeBot::inline_query_placeholder_)
            .def_readwrite("need_location", &td_api::userTypeBot::need_location_);
    
    // No information on the user besides the user identifier is available, yet this user has not been deleted. This object is extremely rare and must be handled like a deleted user. It is not possible to perform any actions on users of this type
    py::class_<td_api::userTypeUnknown>(m, "userTypeUnknown")
            .def(py::init<>());
    
    // Represents a command supported by a bot @command Text of the bot command @param_description Description of the bot command
    py::class_<td_api::botCommand>(m, "botCommand")
            .def(py::init<>())
    
            .def_readwrite("command", &td_api::botCommand::command_)
            .def_readwrite("description", &td_api::botCommand::description_);
    
    // Contains a list of bot commands @bot_user_id Bot's user identifier @commands List of bot commands
    py::class_<td_api::botCommands>(m, "botCommands")
            .def(py::init<>())
    
            .def_readwrite("bot_user_id", &td_api::botCommands::bot_user_id_)
            .def_readwrite("commands", &td_api::botCommands::commands_);
    
    // Represents a location to which a chat is connected @location The location @address Location address; 1-64 characters, as defined by the chat owner
    py::class_<td_api::chatLocation>(m, "chatLocation")
            .def(py::init<>())
    
            .def_readwrite("location", &td_api::chatLocation::location_)
            .def_readwrite("address", &td_api::chatLocation::address_);
    
    // Animated variant of a chat photo in MPEG4 format
    py::class_<td_api::animatedChatPhoto>(m, "animatedChatPhoto")
            .def(py::init<>())
    
            .def_readwrite("length", &td_api::animatedChatPhoto::length_)
            .def_readwrite("file", &td_api::animatedChatPhoto::file_)
            .def_readwrite("main_frame_timestamp", &td_api::animatedChatPhoto::main_frame_timestamp_);
    
    // Describes a chat or user profile photo
    py::class_<td_api::chatPhoto>(m, "chatPhoto")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::chatPhoto::id_)
            .def_readwrite("added_date", &td_api::chatPhoto::added_date_)
            .def_readwrite("minithumbnail", &td_api::chatPhoto::minithumbnail_)
            .def_readwrite("sizes", &td_api::chatPhoto::sizes_)
            .def_readwrite("animation", &td_api::chatPhoto::animation_);
    
    // Contains a list of chat or user profile photos @total_count Total number of photos @photos List of photos
    py::class_<td_api::chatPhotos>(m, "chatPhotos")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::chatPhotos::total_count_)
            .def_readwrite("photos", &td_api::chatPhotos::photos_);
    
    // A previously used profile photo of the current user @chat_photo_id Identifier of the current user's profile photo to reuse
    py::class_<td_api::inputChatPhotoPrevious>(m, "inputChatPhotoPrevious")
            .def(py::init<>())
    
            .def_readwrite("chat_photo_id", &td_api::inputChatPhotoPrevious::chat_photo_id_);
    
    // A static photo in JPEG format @photo Photo to be set as profile photo. Only inputFileLocal and inputFileGenerated are allowed
    py::class_<td_api::inputChatPhotoStatic>(m, "inputChatPhotoStatic")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::inputChatPhotoStatic::photo_);
    
    // An animation in MPEG4 format; must be square, at most 10 seconds long, have width between 160 and 800 and be at most 2MB in size
    py::class_<td_api::inputChatPhotoAnimation>(m, "inputChatPhotoAnimation")
            .def(py::init<>())
    
            .def_readwrite("animation", &td_api::inputChatPhotoAnimation::animation_)
            .def_readwrite("main_frame_timestamp", &td_api::inputChatPhotoAnimation::main_frame_timestamp_);
    
    // Represents a user
    py::class_<td_api::user>(m, "user")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::user::id_)
            .def_readwrite("first_name", &td_api::user::first_name_)
            .def_readwrite("last_name", &td_api::user::last_name_)
            .def_readwrite("username", &td_api::user::username_)
            .def_readwrite("phone_number", &td_api::user::phone_number_)
            .def_readwrite("status", &td_api::user::status_)
            .def_readwrite("profile_photo", &td_api::user::profile_photo_)
            .def_readwrite("is_contact", &td_api::user::is_contact_)
            .def_readwrite("is_mutual_contact", &td_api::user::is_mutual_contact_)
            .def_readwrite("is_verified", &td_api::user::is_verified_)
            .def_readwrite("is_support", &td_api::user::is_support_)
            .def_readwrite("restriction_reason", &td_api::user::restriction_reason_)
            .def_readwrite("is_scam", &td_api::user::is_scam_)
            .def_readwrite("is_fake", &td_api::user::is_fake_)
            .def_readwrite("have_access", &td_api::user::have_access_)
            .def_readwrite("type", &td_api::user::type_)
            .def_readwrite("language_code", &td_api::user::language_code_);
    
    // Contains full information about a user
    py::class_<td_api::userFullInfo>(m, "userFullInfo")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::userFullInfo::photo_)
            .def_readwrite("is_blocked", &td_api::userFullInfo::is_blocked_)
            .def_readwrite("can_be_called", &td_api::userFullInfo::can_be_called_)
            .def_readwrite("supports_video_calls", &td_api::userFullInfo::supports_video_calls_)
            .def_readwrite("has_private_calls", &td_api::userFullInfo::has_private_calls_)
            .def_readwrite("need_phone_number_privacy_exception", &td_api::userFullInfo::need_phone_number_privacy_exception_)
            .def_readwrite("bio", &td_api::userFullInfo::bio_)
            .def_readwrite("share_text", &td_api::userFullInfo::share_text_)
            .def_readwrite("description", &td_api::userFullInfo::description_)
            .def_readwrite("group_in_common_count", &td_api::userFullInfo::group_in_common_count_)
            .def_readwrite("commands", &td_api::userFullInfo::commands_);
    
    // Represents a list of users @total_count Approximate total count of users found @user_ids A list of user identifiers
    py::class_<td_api::users>(m, "users")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::users::total_count_)
            .def_readwrite("user_ids", &td_api::users::user_ids_);
    
    // Contains information about a chat administrator @user_id User identifier of the administrator @custom_title Custom title of the administrator @is_owner True, if the user is the owner of the chat
    py::class_<td_api::chatAdministrator>(m, "chatAdministrator")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatAdministrator::user_id_)
            .def_readwrite("custom_title", &td_api::chatAdministrator::custom_title_)
            .def_readwrite("is_owner", &td_api::chatAdministrator::is_owner_);
    
    // Represents a list of chat administrators @administrators A list of chat administrators
    py::class_<td_api::chatAdministrators>(m, "chatAdministrators")
            .def(py::init<>())
    
            .def_readwrite("administrators", &td_api::chatAdministrators::administrators_);
    
    // Describes actions that a user is allowed to take in a chat
    py::class_<td_api::chatPermissions>(m, "chatPermissions")
            .def(py::init<>())
    
            .def_readwrite("can_send_messages", &td_api::chatPermissions::can_send_messages_)
            .def_readwrite("can_send_media_messages", &td_api::chatPermissions::can_send_media_messages_)
            .def_readwrite("can_send_polls", &td_api::chatPermissions::can_send_polls_)
            .def_readwrite("can_send_other_messages", &td_api::chatPermissions::can_send_other_messages_)
            .def_readwrite("can_add_web_page_previews", &td_api::chatPermissions::can_add_web_page_previews_)
            .def_readwrite("can_change_info", &td_api::chatPermissions::can_change_info_)
            .def_readwrite("can_invite_users", &td_api::chatPermissions::can_invite_users_)
            .def_readwrite("can_pin_messages", &td_api::chatPermissions::can_pin_messages_);
    
    // The user is the owner of the chat and has all the administrator privileges
    py::class_<td_api::chatMemberStatusCreator>(m, "chatMemberStatusCreator")
            .def(py::init<>())
    
            .def_readwrite("custom_title", &td_api::chatMemberStatusCreator::custom_title_)
            .def_readwrite("is_anonymous", &td_api::chatMemberStatusCreator::is_anonymous_)
            .def_readwrite("is_member", &td_api::chatMemberStatusCreator::is_member_);
    
    // The user is a member of the chat and has some additional privileges. In basic groups, administrators can edit and delete messages sent by others, add new members, ban unprivileged members, and manage voice chats. In supergroups and channels, there are more detailed options for administrator privileges
    py::class_<td_api::chatMemberStatusAdministrator>(m, "chatMemberStatusAdministrator")
            .def(py::init<>())
    
            .def_readwrite("custom_title", &td_api::chatMemberStatusAdministrator::custom_title_)
            .def_readwrite("can_be_edited", &td_api::chatMemberStatusAdministrator::can_be_edited_)
            .def_readwrite("can_manage_chat", &td_api::chatMemberStatusAdministrator::can_manage_chat_)
            .def_readwrite("can_change_info", &td_api::chatMemberStatusAdministrator::can_change_info_)
            .def_readwrite("can_post_messages", &td_api::chatMemberStatusAdministrator::can_post_messages_)
            .def_readwrite("can_edit_messages", &td_api::chatMemberStatusAdministrator::can_edit_messages_)
            .def_readwrite("can_delete_messages", &td_api::chatMemberStatusAdministrator::can_delete_messages_)
            .def_readwrite("can_invite_users", &td_api::chatMemberStatusAdministrator::can_invite_users_)
            .def_readwrite("can_restrict_members", &td_api::chatMemberStatusAdministrator::can_restrict_members_)
            .def_readwrite("can_pin_messages", &td_api::chatMemberStatusAdministrator::can_pin_messages_)
            .def_readwrite("can_promote_members", &td_api::chatMemberStatusAdministrator::can_promote_members_)
            .def_readwrite("can_manage_voice_chats", &td_api::chatMemberStatusAdministrator::can_manage_voice_chats_)
            .def_readwrite("is_anonymous", &td_api::chatMemberStatusAdministrator::is_anonymous_);
    
    // The user is a member of the chat, without any additional privileges or restrictions
    py::class_<td_api::chatMemberStatusMember>(m, "chatMemberStatusMember")
            .def(py::init<>());
    
    // The user is under certain restrictions in the chat. Not supported in basic groups and channels
    py::class_<td_api::chatMemberStatusRestricted>(m, "chatMemberStatusRestricted")
            .def(py::init<>())
    
            .def_readwrite("is_member", &td_api::chatMemberStatusRestricted::is_member_)
            .def_readwrite("restricted_until_date", &td_api::chatMemberStatusRestricted::restricted_until_date_)
            .def_readwrite("permissions", &td_api::chatMemberStatusRestricted::permissions_);
    
    // The user or the chat is not a chat member
    py::class_<td_api::chatMemberStatusLeft>(m, "chatMemberStatusLeft")
            .def(py::init<>());
    
    // The user or the chat was banned (and hence is not a member of the chat). Implies the user can't return to the chat, view messages, or be used as a participant identifier to join a voice chat of the chat
    py::class_<td_api::chatMemberStatusBanned>(m, "chatMemberStatusBanned")
            .def(py::init<>())
    
            .def_readwrite("banned_until_date", &td_api::chatMemberStatusBanned::banned_until_date_);
    
    // Information about a user or a chat as a member of another chat
    py::class_<td_api::chatMember>(m, "chatMember")
            .def(py::init<>())
    
            .def_readwrite("member_id", &td_api::chatMember::member_id_)
            .def_readwrite("inviter_user_id", &td_api::chatMember::inviter_user_id_)
            .def_readwrite("joined_chat_date", &td_api::chatMember::joined_chat_date_)
            .def_readwrite("status", &td_api::chatMember::status_);
    
    // Contains a list of chat members @total_count Approximate total count of chat members found @members A list of chat members
    py::class_<td_api::chatMembers>(m, "chatMembers")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::chatMembers::total_count_)
            .def_readwrite("members", &td_api::chatMembers::members_);
    
    // Returns contacts of the user
    py::class_<td_api::chatMembersFilterContacts>(m, "chatMembersFilterContacts")
            .def(py::init<>());
    
    // Returns the owner and administrators
    py::class_<td_api::chatMembersFilterAdministrators>(m, "chatMembersFilterAdministrators")
            .def(py::init<>());
    
    // Returns all chat members, including restricted chat members
    py::class_<td_api::chatMembersFilterMembers>(m, "chatMembersFilterMembers")
            .def(py::init<>());
    
    // Returns users which can be mentioned in the chat @message_thread_id If non-zero, the identifier of the current message thread
    py::class_<td_api::chatMembersFilterMention>(m, "chatMembersFilterMention")
            .def(py::init<>())
    
            .def_readwrite("message_thread_id", &td_api::chatMembersFilterMention::message_thread_id_);
    
    // Returns users under certain restrictions in the chat; can be used only by administrators in a supergroup
    py::class_<td_api::chatMembersFilterRestricted>(m, "chatMembersFilterRestricted")
            .def(py::init<>());
    
    // Returns users banned from the chat; can be used only by administrators in a supergroup or in a channel
    py::class_<td_api::chatMembersFilterBanned>(m, "chatMembersFilterBanned")
            .def(py::init<>());
    
    // Returns bot members of the chat
    py::class_<td_api::chatMembersFilterBots>(m, "chatMembersFilterBots")
            .def(py::init<>());
    
    // Returns recently active users in reverse chronological order
    py::class_<td_api::supergroupMembersFilterRecent>(m, "supergroupMembersFilterRecent")
            .def(py::init<>());
    
    // Returns contacts of the user, which are members of the supergroup or channel @query Query to search for
    py::class_<td_api::supergroupMembersFilterContacts>(m, "supergroupMembersFilterContacts")
            .def(py::init<>())
    
            .def_readwrite("query", &td_api::supergroupMembersFilterContacts::query_);
    
    // Returns the owner and administrators
    py::class_<td_api::supergroupMembersFilterAdministrators>(m, "supergroupMembersFilterAdministrators")
            .def(py::init<>());
    
    // Used to search for supergroup or channel members via a (string) query @query Query to search for
    py::class_<td_api::supergroupMembersFilterSearch>(m, "supergroupMembersFilterSearch")
            .def(py::init<>())
    
            .def_readwrite("query", &td_api::supergroupMembersFilterSearch::query_);
    
    // Returns restricted supergroup members; can be used only by administrators @query Query to search for
    py::class_<td_api::supergroupMembersFilterRestricted>(m, "supergroupMembersFilterRestricted")
            .def(py::init<>())
    
            .def_readwrite("query", &td_api::supergroupMembersFilterRestricted::query_);
    
    // Returns users banned from the supergroup or channel; can be used only by administrators @query Query to search for
    py::class_<td_api::supergroupMembersFilterBanned>(m, "supergroupMembersFilterBanned")
            .def(py::init<>())
    
            .def_readwrite("query", &td_api::supergroupMembersFilterBanned::query_);
    
    // Returns users which can be mentioned in the supergroup @query Query to search for @message_thread_id If non-zero, the identifier of the current message thread
    py::class_<td_api::supergroupMembersFilterMention>(m, "supergroupMembersFilterMention")
            .def(py::init<>())
    
            .def_readwrite("query", &td_api::supergroupMembersFilterMention::query_)
            .def_readwrite("message_thread_id", &td_api::supergroupMembersFilterMention::message_thread_id_);
    
    // Returns bot members of the supergroup or channel
    py::class_<td_api::supergroupMembersFilterBots>(m, "supergroupMembersFilterBots")
            .def(py::init<>());
    
    // Contains a chat invite link @invite_link Chat invite link @creator_user_id User identifier of an administrator created the link
    py::class_<td_api::chatInviteLink>(m, "chatInviteLink")
            .def(py::init<>())
    
            .def_readwrite("invite_link", &td_api::chatInviteLink::invite_link_)
            .def_readwrite("creator_user_id", &td_api::chatInviteLink::creator_user_id_)
            .def_readwrite("date", &td_api::chatInviteLink::date_)
            .def_readwrite("edit_date", &td_api::chatInviteLink::edit_date_)
            .def_readwrite("expire_date", &td_api::chatInviteLink::expire_date_)
            .def_readwrite("member_limit", &td_api::chatInviteLink::member_limit_)
            .def_readwrite("member_count", &td_api::chatInviteLink::member_count_)
            .def_readwrite("is_primary", &td_api::chatInviteLink::is_primary_)
            .def_readwrite("is_revoked", &td_api::chatInviteLink::is_revoked_);
    
    // Contains a list of chat invite links @total_count Approximate total count of chat invite links found @invite_links List of invite links
    py::class_<td_api::chatInviteLinks>(m, "chatInviteLinks")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::chatInviteLinks::total_count_)
            .def_readwrite("invite_links", &td_api::chatInviteLinks::invite_links_);
    
    // Describes a chat administrator with a number of active and revoked chat invite links
    py::class_<td_api::chatInviteLinkCount>(m, "chatInviteLinkCount")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatInviteLinkCount::user_id_)
            .def_readwrite("invite_link_count", &td_api::chatInviteLinkCount::invite_link_count_)
            .def_readwrite("revoked_invite_link_count", &td_api::chatInviteLinkCount::revoked_invite_link_count_);
    
    // Contains a list of chat invite link counts @invite_link_counts List of invite linkcounts
    py::class_<td_api::chatInviteLinkCounts>(m, "chatInviteLinkCounts")
            .def(py::init<>())
    
            .def_readwrite("invite_link_counts", &td_api::chatInviteLinkCounts::invite_link_counts_);
    
    // Describes a chat member joined a chat by an invite link @user_id User identifier @joined_chat_date Point in time (Unix timestamp) when the user joined the chat
    py::class_<td_api::chatInviteLinkMember>(m, "chatInviteLinkMember")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatInviteLinkMember::user_id_)
            .def_readwrite("joined_chat_date", &td_api::chatInviteLinkMember::joined_chat_date_);
    
    // Contains a list of chat members joined a chat by an invite link @total_count Approximate total count of chat members found @members List of chat members, joined a chat by an invite link
    py::class_<td_api::chatInviteLinkMembers>(m, "chatInviteLinkMembers")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::chatInviteLinkMembers::total_count_)
            .def_readwrite("members", &td_api::chatInviteLinkMembers::members_);
    
    // Contains information about a chat invite link
    py::class_<td_api::chatInviteLinkInfo>(m, "chatInviteLinkInfo")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::chatInviteLinkInfo::chat_id_)
            .def_readwrite("accessible_for", &td_api::chatInviteLinkInfo::accessible_for_)
            .def_readwrite("type", &td_api::chatInviteLinkInfo::type_)
            .def_readwrite("title", &td_api::chatInviteLinkInfo::title_)
            .def_readwrite("photo", &td_api::chatInviteLinkInfo::photo_)
            .def_readwrite("member_count", &td_api::chatInviteLinkInfo::member_count_)
            .def_readwrite("member_user_ids", &td_api::chatInviteLinkInfo::member_user_ids_)
            .def_readwrite("is_public", &td_api::chatInviteLinkInfo::is_public_);
    
    // Represents a basic group of 0-200 users (must be upgraded to a supergroup to accommodate more than 200 users)
    py::class_<td_api::basicGroup>(m, "basicGroup")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::basicGroup::id_)
            .def_readwrite("member_count", &td_api::basicGroup::member_count_)
            .def_readwrite("status", &td_api::basicGroup::status_)
            .def_readwrite("is_active", &td_api::basicGroup::is_active_)
            .def_readwrite("upgraded_to_supergroup_id", &td_api::basicGroup::upgraded_to_supergroup_id_);
    
    // Contains full information about a basic group
    py::class_<td_api::basicGroupFullInfo>(m, "basicGroupFullInfo")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::basicGroupFullInfo::photo_)
            .def_readwrite("description", &td_api::basicGroupFullInfo::description_)
            .def_readwrite("creator_user_id", &td_api::basicGroupFullInfo::creator_user_id_)
            .def_readwrite("members", &td_api::basicGroupFullInfo::members_)
            .def_readwrite("invite_link", &td_api::basicGroupFullInfo::invite_link_)
            .def_readwrite("bot_commands", &td_api::basicGroupFullInfo::bot_commands_);
    
    // Represents a supergroup or channel with zero or more members (subscribers in the case of channels). From the point of view of the system, a channel is a special kind of a supergroup: only administrators can post and see the list of members, and posts from all administrators use the name and photo of the channel instead of individual names and profile photos. Unlike supergroups, channels can have an unlimited number of subscribers
    py::class_<td_api::supergroup>(m, "supergroup")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::supergroup::id_)
            .def_readwrite("username", &td_api::supergroup::username_)
            .def_readwrite("date", &td_api::supergroup::date_)
            .def_readwrite("status", &td_api::supergroup::status_)
            .def_readwrite("member_count", &td_api::supergroup::member_count_)
            .def_readwrite("has_linked_chat", &td_api::supergroup::has_linked_chat_)
            .def_readwrite("has_location", &td_api::supergroup::has_location_)
            .def_readwrite("sign_messages", &td_api::supergroup::sign_messages_)
            .def_readwrite("is_slow_mode_enabled", &td_api::supergroup::is_slow_mode_enabled_)
            .def_readwrite("is_channel", &td_api::supergroup::is_channel_)
            .def_readwrite("is_broadcast_group", &td_api::supergroup::is_broadcast_group_)
            .def_readwrite("is_verified", &td_api::supergroup::is_verified_)
            .def_readwrite("restriction_reason", &td_api::supergroup::restriction_reason_)
            .def_readwrite("is_scam", &td_api::supergroup::is_scam_)
            .def_readwrite("is_fake", &td_api::supergroup::is_fake_);
    
    // Contains full information about a supergroup or channel
    py::class_<td_api::supergroupFullInfo>(m, "supergroupFullInfo")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::supergroupFullInfo::photo_)
            .def_readwrite("description", &td_api::supergroupFullInfo::description_)
            .def_readwrite("member_count", &td_api::supergroupFullInfo::member_count_)
            .def_readwrite("administrator_count", &td_api::supergroupFullInfo::administrator_count_)
            .def_readwrite("restricted_count", &td_api::supergroupFullInfo::restricted_count_)
            .def_readwrite("banned_count", &td_api::supergroupFullInfo::banned_count_)
            .def_readwrite("linked_chat_id", &td_api::supergroupFullInfo::linked_chat_id_)
            .def_readwrite("slow_mode_delay", &td_api::supergroupFullInfo::slow_mode_delay_)
            .def_readwrite("slow_mode_delay_expires_in", &td_api::supergroupFullInfo::slow_mode_delay_expires_in_)
            .def_readwrite("can_get_members", &td_api::supergroupFullInfo::can_get_members_)
            .def_readwrite("can_set_username", &td_api::supergroupFullInfo::can_set_username_)
            .def_readwrite("can_set_sticker_set", &td_api::supergroupFullInfo::can_set_sticker_set_)
            .def_readwrite("can_set_location", &td_api::supergroupFullInfo::can_set_location_)
            .def_readwrite("can_get_statistics", &td_api::supergroupFullInfo::can_get_statistics_)
            .def_readwrite("is_all_history_available", &td_api::supergroupFullInfo::is_all_history_available_)
            .def_readwrite("sticker_set_id", &td_api::supergroupFullInfo::sticker_set_id_)
            .def_readwrite("location", &td_api::supergroupFullInfo::location_)
            .def_readwrite("invite_link", &td_api::supergroupFullInfo::invite_link_)
            .def_readwrite("bot_commands", &td_api::supergroupFullInfo::bot_commands_)
            .def_readwrite("upgraded_from_basic_group_id", &td_api::supergroupFullInfo::upgraded_from_basic_group_id_)
            .def_readwrite("upgraded_from_max_message_id", &td_api::supergroupFullInfo::upgraded_from_max_message_id_);
    
    // The secret chat is not yet created; waiting for the other user to get online
    py::class_<td_api::secretChatStatePending>(m, "secretChatStatePending")
            .def(py::init<>());
    
    // The secret chat is ready to use
    py::class_<td_api::secretChatStateReady>(m, "secretChatStateReady")
            .def(py::init<>());
    
    // The secret chat is closed
    py::class_<td_api::secretChatStateClosed>(m, "secretChatStateClosed")
            .def(py::init<>());
    
    // Represents a secret chat
    py::class_<td_api::secretChat>(m, "secretChat")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::secretChat::id_)
            .def_readwrite("user_id", &td_api::secretChat::user_id_)
            .def_readwrite("state", &td_api::secretChat::state_)
            .def_readwrite("is_outbound", &td_api::secretChat::is_outbound_)
            .def_readwrite("key_hash", &td_api::secretChat::key_hash_)
            .def_readwrite("layer", &td_api::secretChat::layer_);
    
    // The message was sent by a known user @user_id Identifier of the user that sent the message
    py::class_<td_api::messageSenderUser>(m, "messageSenderUser")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::messageSenderUser::user_id_);
    
    // The message was sent on behalf of a chat @chat_id Identifier of the chat that sent the message
    py::class_<td_api::messageSenderChat>(m, "messageSenderChat")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::messageSenderChat::chat_id_);
    
    // Represents a list of message senders @total_count Approximate total count of messages senders found @senders List of message senders
    py::class_<td_api::messageSenders>(m, "messageSenders")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::messageSenders::total_count_)
            .def_readwrite("senders", &td_api::messageSenders::senders_);
    
    // The message was originally sent by a known user @sender_user_id Identifier of the user that originally sent the message
    py::class_<td_api::messageForwardOriginUser>(m, "messageForwardOriginUser")
            .def(py::init<>())
    
            .def_readwrite("sender_user_id", &td_api::messageForwardOriginUser::sender_user_id_);
    
    // The message was originally sent by an anonymous chat administrator on behalf of the chat
    py::class_<td_api::messageForwardOriginChat>(m, "messageForwardOriginChat")
            .def(py::init<>())
    
            .def_readwrite("sender_chat_id", &td_api::messageForwardOriginChat::sender_chat_id_)
            .def_readwrite("author_signature", &td_api::messageForwardOriginChat::author_signature_);
    
    // The message was originally sent by a user, which is hidden by their privacy settings @sender_name Name of the sender
    py::class_<td_api::messageForwardOriginHiddenUser>(m, "messageForwardOriginHiddenUser")
            .def(py::init<>())
    
            .def_readwrite("sender_name", &td_api::messageForwardOriginHiddenUser::sender_name_);
    
    // The message was originally a post in a channel
    py::class_<td_api::messageForwardOriginChannel>(m, "messageForwardOriginChannel")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::messageForwardOriginChannel::chat_id_)
            .def_readwrite("message_id", &td_api::messageForwardOriginChannel::message_id_)
            .def_readwrite("author_signature", &td_api::messageForwardOriginChannel::author_signature_);
    
    // The message was imported from an exported message history @sender_name Name of the sender
    py::class_<td_api::messageForwardOriginMessageImport>(m, "messageForwardOriginMessageImport")
            .def(py::init<>())
    
            .def_readwrite("sender_name", &td_api::messageForwardOriginMessageImport::sender_name_);
    
    // Contains information about a forwarded message
    py::class_<td_api::messageForwardInfo>(m, "messageForwardInfo")
            .def(py::init<>())
    
            .def_readwrite("origin", &td_api::messageForwardInfo::origin_)
            .def_readwrite("date", &td_api::messageForwardInfo::date_)
            .def_readwrite("public_service_announcement_type", &td_api::messageForwardInfo::public_service_announcement_type_)
            .def_readwrite("from_chat_id", &td_api::messageForwardInfo::from_chat_id_)
            .def_readwrite("from_message_id", &td_api::messageForwardInfo::from_message_id_);
    
    // Contains information about replies to a message
    py::class_<td_api::messageReplyInfo>(m, "messageReplyInfo")
            .def(py::init<>())
    
            .def_readwrite("reply_count", &td_api::messageReplyInfo::reply_count_)
            .def_readwrite("recent_repliers", &td_api::messageReplyInfo::recent_repliers_)
            .def_readwrite("last_read_inbox_message_id", &td_api::messageReplyInfo::last_read_inbox_message_id_)
            .def_readwrite("last_read_outbox_message_id", &td_api::messageReplyInfo::last_read_outbox_message_id_)
            .def_readwrite("last_message_id", &td_api::messageReplyInfo::last_message_id_);
    
    // Contains information about interactions with a message
    py::class_<td_api::messageInteractionInfo>(m, "messageInteractionInfo")
            .def(py::init<>())
    
            .def_readwrite("view_count", &td_api::messageInteractionInfo::view_count_)
            .def_readwrite("forward_count", &td_api::messageInteractionInfo::forward_count_)
            .def_readwrite("reply_info", &td_api::messageInteractionInfo::reply_info_);
    
    // The message is being sent now, but has not yet been delivered to the server
    py::class_<td_api::messageSendingStatePending>(m, "messageSendingStatePending")
            .def(py::init<>());
    
    // The message failed to be sent @error_code An error code; 0 if unknown @error_message Error message
    py::class_<td_api::messageSendingStateFailed>(m, "messageSendingStateFailed")
            .def(py::init<>())
    
            .def_readwrite("error_code", &td_api::messageSendingStateFailed::error_code_)
            .def_readwrite("error_message", &td_api::messageSendingStateFailed::error_message_)
            .def_readwrite("can_retry", &td_api::messageSendingStateFailed::can_retry_)
            .def_readwrite("retry_after", &td_api::messageSendingStateFailed::retry_after_);
    
    // Describes a message
    py::class_<td_api::message>(m, "message")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::message::id_)
            .def_readwrite("sender", &td_api::message::sender_)
            .def_readwrite("chat_id", &td_api::message::chat_id_)
            .def_readwrite("sending_state", &td_api::message::sending_state_)
            .def_readwrite("scheduling_state", &td_api::message::scheduling_state_)
            .def_readwrite("is_outgoing", &td_api::message::is_outgoing_)
            .def_readwrite("is_pinned", &td_api::message::is_pinned_)
            .def_readwrite("can_be_edited", &td_api::message::can_be_edited_)
            .def_readwrite("can_be_forwarded", &td_api::message::can_be_forwarded_)
            .def_readwrite("can_be_deleted_only_for_self", &td_api::message::can_be_deleted_only_for_self_)
            .def_readwrite("can_be_deleted_for_all_users", &td_api::message::can_be_deleted_for_all_users_)
            .def_readwrite("can_get_statistics", &td_api::message::can_get_statistics_)
            .def_readwrite("can_get_message_thread", &td_api::message::can_get_message_thread_)
            .def_readwrite("is_channel_post", &td_api::message::is_channel_post_)
            .def_readwrite("contains_unread_mention", &td_api::message::contains_unread_mention_)
            .def_readwrite("date", &td_api::message::date_)
            .def_readwrite("edit_date", &td_api::message::edit_date_)
            .def_readwrite("forward_info", &td_api::message::forward_info_)
            .def_readwrite("interaction_info", &td_api::message::interaction_info_)
            .def_readwrite("reply_in_chat_id", &td_api::message::reply_in_chat_id_)
            .def_readwrite("reply_to_message_id", &td_api::message::reply_to_message_id_)
            .def_readwrite("message_thread_id", &td_api::message::message_thread_id_)
            .def_readwrite("ttl", &td_api::message::ttl_)
            .def_readwrite("ttl_expires_in", &td_api::message::ttl_expires_in_)
            .def_readwrite("via_bot_user_id", &td_api::message::via_bot_user_id_)
            .def_readwrite("author_signature", &td_api::message::author_signature_)
            .def_readwrite("media_album_id", &td_api::message::media_album_id_)
            .def_readwrite("restriction_reason", &td_api::message::restriction_reason_)
            .def_readwrite("content", &td_api::message::content_)
            .def_readwrite("reply_markup", &td_api::message::reply_markup_);
    
    // Contains a list of messages @total_count Approximate total count of messages found @messages List of messages; messages may be null
    py::class_<td_api::messages>(m, "messages")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::messages::total_count_)
            .def_readwrite("messages", &td_api::messages::messages_);
    
    // Contains a list of messages found by a search @total_count Approximate total count of messages found; -1 if unknown @messages List of messages @next_offset The offset for the next request. If empty, there are no more results
    py::class_<td_api::foundMessages>(m, "foundMessages")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::foundMessages::total_count_)
            .def_readwrite("messages", &td_api::foundMessages::messages_)
            .def_readwrite("next_offset", &td_api::foundMessages::next_offset_);
    
    // Notification settings applied to all private and secret chats when the corresponding chat setting has a default value
    py::class_<td_api::notificationSettingsScopePrivateChats>(m, "notificationSettingsScopePrivateChats")
            .def(py::init<>());
    
    // Notification settings applied to all basic groups and supergroups when the corresponding chat setting has a default value
    py::class_<td_api::notificationSettingsScopeGroupChats>(m, "notificationSettingsScopeGroupChats")
            .def(py::init<>());
    
    // Notification settings applied to all channels when the corresponding chat setting has a default value
    py::class_<td_api::notificationSettingsScopeChannelChats>(m, "notificationSettingsScopeChannelChats")
            .def(py::init<>());
    
    // Contains information about notification settings for a chat
    py::class_<td_api::chatNotificationSettings>(m, "chatNotificationSettings")
            .def(py::init<>())
    
            .def_readwrite("use_default_mute_for", &td_api::chatNotificationSettings::use_default_mute_for_)
            .def_readwrite("mute_for", &td_api::chatNotificationSettings::mute_for_)
            .def_readwrite("use_default_sound", &td_api::chatNotificationSettings::use_default_sound_)
            .def_readwrite("sound", &td_api::chatNotificationSettings::sound_)
            .def_readwrite("use_default_show_preview", &td_api::chatNotificationSettings::use_default_show_preview_)
            .def_readwrite("show_preview", &td_api::chatNotificationSettings::show_preview_)
            .def_readwrite("use_default_disable_pinned_message_notifications", &td_api::chatNotificationSettings::use_default_disable_pinned_message_notifications_)
            .def_readwrite("disable_pinned_message_notifications", &td_api::chatNotificationSettings::disable_pinned_message_notifications_)
            .def_readwrite("use_default_disable_mention_notifications", &td_api::chatNotificationSettings::use_default_disable_mention_notifications_)
            .def_readwrite("disable_mention_notifications", &td_api::chatNotificationSettings::disable_mention_notifications_);
    
    // Contains information about notification settings for several chats
    py::class_<td_api::scopeNotificationSettings>(m, "scopeNotificationSettings")
            .def(py::init<>())
    
            .def_readwrite("mute_for", &td_api::scopeNotificationSettings::mute_for_)
            .def_readwrite("sound", &td_api::scopeNotificationSettings::sound_)
            .def_readwrite("show_preview", &td_api::scopeNotificationSettings::show_preview_)
            .def_readwrite("disable_pinned_message_notifications", &td_api::scopeNotificationSettings::disable_pinned_message_notifications_)
            .def_readwrite("disable_mention_notifications", &td_api::scopeNotificationSettings::disable_mention_notifications_);
    
    // Contains information about a message draft
    py::class_<td_api::draftMessage>(m, "draftMessage")
            .def(py::init<>())
    
            .def_readwrite("reply_to_message_id", &td_api::draftMessage::reply_to_message_id_)
            .def_readwrite("date", &td_api::draftMessage::date_)
            .def_readwrite("input_message_text", &td_api::draftMessage::input_message_text_);
    
    // An ordinary chat with a user @user_id User identifier
    py::class_<td_api::chatTypePrivate>(m, "chatTypePrivate")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatTypePrivate::user_id_);
    
    // A basic group (i.e., a chat with 0-200 other users) @basic_group_id Basic group identifier
    py::class_<td_api::chatTypeBasicGroup>(m, "chatTypeBasicGroup")
            .def(py::init<>())
    
            .def_readwrite("basic_group_id", &td_api::chatTypeBasicGroup::basic_group_id_);
    
    // A supergroup (i.e. a chat with up to GetOption("supergroup_max_size") other users), or channel (with unlimited members) @supergroup_id Supergroup or channel identifier @is_channel True, if the supergroup is a channel
    py::class_<td_api::chatTypeSupergroup>(m, "chatTypeSupergroup")
            .def(py::init<>())
    
            .def_readwrite("supergroup_id", &td_api::chatTypeSupergroup::supergroup_id_)
            .def_readwrite("is_channel", &td_api::chatTypeSupergroup::is_channel_);
    
    // A secret chat with a user @secret_chat_id Secret chat identifier @user_id User identifier of the secret chat peer
    py::class_<td_api::chatTypeSecret>(m, "chatTypeSecret")
            .def(py::init<>())
    
            .def_readwrite("secret_chat_id", &td_api::chatTypeSecret::secret_chat_id_)
            .def_readwrite("user_id", &td_api::chatTypeSecret::user_id_);
    
    // Represents a filter of user chats
    py::class_<td_api::chatFilter>(m, "chatFilter")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::chatFilter::title_)
            .def_readwrite("icon_name", &td_api::chatFilter::icon_name_)
            .def_readwrite("pinned_chat_ids", &td_api::chatFilter::pinned_chat_ids_)
            .def_readwrite("included_chat_ids", &td_api::chatFilter::included_chat_ids_)
            .def_readwrite("excluded_chat_ids", &td_api::chatFilter::excluded_chat_ids_)
            .def_readwrite("exclude_muted", &td_api::chatFilter::exclude_muted_)
            .def_readwrite("exclude_read", &td_api::chatFilter::exclude_read_)
            .def_readwrite("exclude_archived", &td_api::chatFilter::exclude_archived_)
            .def_readwrite("include_contacts", &td_api::chatFilter::include_contacts_)
            .def_readwrite("include_non_contacts", &td_api::chatFilter::include_non_contacts_)
            .def_readwrite("include_bots", &td_api::chatFilter::include_bots_)
            .def_readwrite("include_groups", &td_api::chatFilter::include_groups_)
            .def_readwrite("include_channels", &td_api::chatFilter::include_channels_);
    
    // Contains basic information about a chat filter
    py::class_<td_api::chatFilterInfo>(m, "chatFilterInfo")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::chatFilterInfo::id_)
            .def_readwrite("title", &td_api::chatFilterInfo::title_)
            .def_readwrite("icon_name", &td_api::chatFilterInfo::icon_name_);
    
    // Describes a recommended chat filter @filter The chat filter @param_description Chat filter description
    py::class_<td_api::recommendedChatFilter>(m, "recommendedChatFilter")
            .def(py::init<>())
    
            .def_readwrite("filter", &td_api::recommendedChatFilter::filter_)
            .def_readwrite("description", &td_api::recommendedChatFilter::description_);
    
    // Contains a list of recommended chat filters @chat_filters List of recommended chat filters
    py::class_<td_api::recommendedChatFilters>(m, "recommendedChatFilters")
            .def(py::init<>())
    
            .def_readwrite("chat_filters", &td_api::recommendedChatFilters::chat_filters_);
    
    // A main list of chats
    py::class_<td_api::chatListMain>(m, "chatListMain")
            .def(py::init<>());
    
    // A list of chats usually located at the top of the main chat list. Unmuted chats are automatically moved from the Archive to the Main chat list when a new message arrives
    py::class_<td_api::chatListArchive>(m, "chatListArchive")
            .def(py::init<>());
    
    // A list of chats belonging to a chat filter @chat_filter_id Chat filter identifier
    py::class_<td_api::chatListFilter>(m, "chatListFilter")
            .def(py::init<>())
    
            .def_readwrite("chat_filter_id", &td_api::chatListFilter::chat_filter_id_);
    
    // Contains a list of chat lists @chat_lists List of chat lists
    py::class_<td_api::chatLists>(m, "chatLists")
            .def(py::init<>())
    
            .def_readwrite("chat_lists", &td_api::chatLists::chat_lists_);
    
    // The chat is sponsored by the user's MTProxy server
    py::class_<td_api::chatSourceMtprotoProxy>(m, "chatSourceMtprotoProxy")
            .def(py::init<>());
    
    // The chat contains a public service announcement @type The type of the announcement @text The text of the announcement
    py::class_<td_api::chatSourcePublicServiceAnnouncement>(m, "chatSourcePublicServiceAnnouncement")
            .def(py::init<>())
    
            .def_readwrite("type", &td_api::chatSourcePublicServiceAnnouncement::type_)
            .def_readwrite("text", &td_api::chatSourcePublicServiceAnnouncement::text_);
    
    // Describes a position of a chat in a chat list
    py::class_<td_api::chatPosition>(m, "chatPosition")
            .def(py::init<>())
    
            .def_readwrite("list", &td_api::chatPosition::list_)
            .def_readwrite("order", &td_api::chatPosition::order_)
            .def_readwrite("is_pinned", &td_api::chatPosition::is_pinned_)
            .def_readwrite("source", &td_api::chatPosition::source_);
    
    // Describes a voice chat
    py::class_<td_api::voiceChat>(m, "voiceChat")
            .def(py::init<>())
    
            .def_readwrite("group_call_id", &td_api::voiceChat::group_call_id_)
            .def_readwrite("has_participants", &td_api::voiceChat::has_participants_)
            .def_readwrite("default_participant_id", &td_api::voiceChat::default_participant_id_);
    
    // A chat. (Can be a private chat, basic group, supergroup, or secret chat)
    py::class_<td_api::chat>(m, "chat")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::chat::id_)
            .def_readwrite("type", &td_api::chat::type_)
            .def_readwrite("title", &td_api::chat::title_)
            .def_readwrite("photo", &td_api::chat::photo_)
            .def_readwrite("permissions", &td_api::chat::permissions_)
            .def_readwrite("last_message", &td_api::chat::last_message_)
            .def_readwrite("positions", &td_api::chat::positions_)
            .def_readwrite("is_marked_as_unread", &td_api::chat::is_marked_as_unread_)
            .def_readwrite("is_blocked", &td_api::chat::is_blocked_)
            .def_readwrite("has_scheduled_messages", &td_api::chat::has_scheduled_messages_)
            .def_readwrite("can_be_deleted_only_for_self", &td_api::chat::can_be_deleted_only_for_self_)
            .def_readwrite("can_be_deleted_for_all_users", &td_api::chat::can_be_deleted_for_all_users_)
            .def_readwrite("can_be_reported", &td_api::chat::can_be_reported_)
            .def_readwrite("default_disable_notification", &td_api::chat::default_disable_notification_)
            .def_readwrite("unread_count", &td_api::chat::unread_count_)
            .def_readwrite("last_read_inbox_message_id", &td_api::chat::last_read_inbox_message_id_)
            .def_readwrite("last_read_outbox_message_id", &td_api::chat::last_read_outbox_message_id_)
            .def_readwrite("unread_mention_count", &td_api::chat::unread_mention_count_)
            .def_readwrite("notification_settings", &td_api::chat::notification_settings_)
            .def_readwrite("message_ttl_setting", &td_api::chat::message_ttl_setting_)
            .def_readwrite("action_bar", &td_api::chat::action_bar_)
            .def_readwrite("voice_chat", &td_api::chat::voice_chat_)
            .def_readwrite("reply_markup_message_id", &td_api::chat::reply_markup_message_id_)
            .def_readwrite("draft_message", &td_api::chat::draft_message_)
            .def_readwrite("client_data", &td_api::chat::client_data_);
    
    // Represents a list of chats @total_count Approximate total count of chats found @chat_ids List of chat identifiers
    py::class_<td_api::chats>(m, "chats")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::chats::total_count_)
            .def_readwrite("chat_ids", &td_api::chats::chat_ids_);
    
    // Describes a chat located nearby @chat_id Chat identifier @distance Distance to the chat location, in meters
    py::class_<td_api::chatNearby>(m, "chatNearby")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::chatNearby::chat_id_)
            .def_readwrite("distance", &td_api::chatNearby::distance_);
    
    // Represents a list of chats located nearby @users_nearby List of users nearby @supergroups_nearby List of location-based supergroups nearby
    py::class_<td_api::chatsNearby>(m, "chatsNearby")
            .def(py::init<>())
    
            .def_readwrite("users_nearby", &td_api::chatsNearby::users_nearby_)
            .def_readwrite("supergroups_nearby", &td_api::chatsNearby::supergroups_nearby_);
    
    // The chat is public, because it has username
    py::class_<td_api::publicChatTypeHasUsername>(m, "publicChatTypeHasUsername")
            .def(py::init<>());
    
    // The chat is public, because it is a location-based supergroup
    py::class_<td_api::publicChatTypeIsLocationBased>(m, "publicChatTypeIsLocationBased")
            .def(py::init<>());
    
    // The chat can be reported as spam using the method reportChat with the reason chatReportReasonSpam
    py::class_<td_api::chatActionBarReportSpam>(m, "chatActionBarReportSpam")
            .def(py::init<>())
    
            .def_readwrite("can_unarchive", &td_api::chatActionBarReportSpam::can_unarchive_);
    
    // The chat is a location-based supergroup, which can be reported as having unrelated location using the method reportChat with the reason chatReportReasonUnrelatedLocation
    py::class_<td_api::chatActionBarReportUnrelatedLocation>(m, "chatActionBarReportUnrelatedLocation")
            .def(py::init<>());
    
    // The chat is a recently created group chat, to which new members can be invited
    py::class_<td_api::chatActionBarInviteMembers>(m, "chatActionBarInviteMembers")
            .def(py::init<>());
    
    // The chat is a private or secret chat, which can be reported using the method reportChat, or the other user can be blocked using the method blockUser, or the other user can be added to the contact list using the method addContact
    py::class_<td_api::chatActionBarReportAddBlock>(m, "chatActionBarReportAddBlock")
            .def(py::init<>())
    
            .def_readwrite("can_unarchive", &td_api::chatActionBarReportAddBlock::can_unarchive_)
            .def_readwrite("distance", &td_api::chatActionBarReportAddBlock::distance_);
    
    // The chat is a private or secret chat and the other user can be added to the contact list using the method addContact
    py::class_<td_api::chatActionBarAddContact>(m, "chatActionBarAddContact")
            .def(py::init<>());
    
    // The chat is a private or secret chat with a mutual contact and the user's phone number can be shared with the other user using the method sharePhoneNumber
    py::class_<td_api::chatActionBarSharePhoneNumber>(m, "chatActionBarSharePhoneNumber")
            .def(py::init<>());
    
    // A simple button, with text that should be sent when the button is pressed
    py::class_<td_api::keyboardButtonTypeText>(m, "keyboardButtonTypeText")
            .def(py::init<>());
    
    // A button that sends the user's phone number when pressed; available only in private chats
    py::class_<td_api::keyboardButtonTypeRequestPhoneNumber>(m, "keyboardButtonTypeRequestPhoneNumber")
            .def(py::init<>());
    
    // A button that sends the user's location when pressed; available only in private chats
    py::class_<td_api::keyboardButtonTypeRequestLocation>(m, "keyboardButtonTypeRequestLocation")
            .def(py::init<>());
    
    // A button that allows the user to create and send a poll when pressed; available only in private chats @force_regular If true, only regular polls must be allowed to create @force_quiz If true, only polls in quiz mode must be allowed to create
    py::class_<td_api::keyboardButtonTypeRequestPoll>(m, "keyboardButtonTypeRequestPoll")
            .def(py::init<>())
    
            .def_readwrite("force_regular", &td_api::keyboardButtonTypeRequestPoll::force_regular_)
            .def_readwrite("force_quiz", &td_api::keyboardButtonTypeRequestPoll::force_quiz_);
    
    // Represents a single button in a bot keyboard @text Text of the button @type Type of the button
    py::class_<td_api::keyboardButton>(m, "keyboardButton")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::keyboardButton::text_)
            .def_readwrite("type", &td_api::keyboardButton::type_);
    
    // A button that opens a specified URL @url HTTP or tg:// URL to open
    py::class_<td_api::inlineKeyboardButtonTypeUrl>(m, "inlineKeyboardButtonTypeUrl")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::inlineKeyboardButtonTypeUrl::url_);
    
    // A button that opens a specified URL and automatically authorize the current user if allowed to do so @url An HTTP URL to open @id Unique button identifier @forward_text If non-empty, new text of the button in forwarded messages
    py::class_<td_api::inlineKeyboardButtonTypeLoginUrl>(m, "inlineKeyboardButtonTypeLoginUrl")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::inlineKeyboardButtonTypeLoginUrl::url_)
            .def_readwrite("id", &td_api::inlineKeyboardButtonTypeLoginUrl::id_)
            .def_readwrite("forward_text", &td_api::inlineKeyboardButtonTypeLoginUrl::forward_text_);
    
    // A button that sends a callback query to a bot @data Data to be sent to the bot via a callback query
    py::class_<td_api::inlineKeyboardButtonTypeCallback>(m, "inlineKeyboardButtonTypeCallback")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::inlineKeyboardButtonTypeCallback::data_);
    
    // A button that asks for password of the current user and then sends a callback query to a bot @data Data to be sent to the bot via a callback query
    py::class_<td_api::inlineKeyboardButtonTypeCallbackWithPassword>(m, "inlineKeyboardButtonTypeCallbackWithPassword")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::inlineKeyboardButtonTypeCallbackWithPassword::data_);
    
    // A button with a game that sends a callback query to a bot. This button must be in the first column and row of the keyboard and can be attached only to a message with content of the type messageGame
    py::class_<td_api::inlineKeyboardButtonTypeCallbackGame>(m, "inlineKeyboardButtonTypeCallbackGame")
            .def(py::init<>());
    
    // A button that forces an inline query to the bot to be inserted in the input field @query Inline query to be sent to the bot @in_current_chat True, if the inline query should be sent from the current chat
    py::class_<td_api::inlineKeyboardButtonTypeSwitchInline>(m, "inlineKeyboardButtonTypeSwitchInline")
            .def(py::init<>())
    
            .def_readwrite("query", &td_api::inlineKeyboardButtonTypeSwitchInline::query_)
            .def_readwrite("in_current_chat", &td_api::inlineKeyboardButtonTypeSwitchInline::in_current_chat_);
    
    // A button to buy something. This button must be in the first column and row of the keyboard and can be attached only to a message with content of the type messageInvoice
    py::class_<td_api::inlineKeyboardButtonTypeBuy>(m, "inlineKeyboardButtonTypeBuy")
            .def(py::init<>());
    
    // Represents a single button in an inline keyboard @text Text of the button @type Type of the button
    py::class_<td_api::inlineKeyboardButton>(m, "inlineKeyboardButton")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::inlineKeyboardButton::text_)
            .def_readwrite("type", &td_api::inlineKeyboardButton::type_);
    
    // Instructs application to remove the keyboard once this message has been received. This kind of keyboard can't be received in an incoming message; instead, UpdateChatReplyMarkup with message_id == 0 will be sent
    py::class_<td_api::replyMarkupRemoveKeyboard>(m, "replyMarkupRemoveKeyboard")
            .def(py::init<>())
    
            .def_readwrite("is_personal", &td_api::replyMarkupRemoveKeyboard::is_personal_);
    
    // Instructs application to force a reply to this message
    py::class_<td_api::replyMarkupForceReply>(m, "replyMarkupForceReply")
            .def(py::init<>())
    
            .def_readwrite("is_personal", &td_api::replyMarkupForceReply::is_personal_)
            .def_readwrite("input_field_placeholder", &td_api::replyMarkupForceReply::input_field_placeholder_);
    
    // Contains a custom keyboard layout to quickly reply to bots
    py::class_<td_api::replyMarkupShowKeyboard>(m, "replyMarkupShowKeyboard")
            .def(py::init<>())
    
            .def_readwrite("rows", &td_api::replyMarkupShowKeyboard::rows_)
            .def_readwrite("resize_keyboard", &td_api::replyMarkupShowKeyboard::resize_keyboard_)
            .def_readwrite("one_time", &td_api::replyMarkupShowKeyboard::one_time_)
            .def_readwrite("is_personal", &td_api::replyMarkupShowKeyboard::is_personal_)
            .def_readwrite("input_field_placeholder", &td_api::replyMarkupShowKeyboard::input_field_placeholder_);
    
    // Contains an inline keyboard layout
    py::class_<td_api::replyMarkupInlineKeyboard>(m, "replyMarkupInlineKeyboard")
            .def(py::init<>())
    
            .def_readwrite("rows", &td_api::replyMarkupInlineKeyboard::rows_);
    
    // An HTTP url needs to be open @url The URL to open @skip_confirm True, if there is no need to show an ordinary open URL confirm
    py::class_<td_api::loginUrlInfoOpen>(m, "loginUrlInfoOpen")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::loginUrlInfoOpen::url_)
            .def_readwrite("skip_confirm", &td_api::loginUrlInfoOpen::skip_confirm_);
    
    // An authorization confirmation dialog needs to be shown to the user @url An HTTP URL to be opened @domain A domain of the URL
    py::class_<td_api::loginUrlInfoRequestConfirmation>(m, "loginUrlInfoRequestConfirmation")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::loginUrlInfoRequestConfirmation::url_)
            .def_readwrite("domain", &td_api::loginUrlInfoRequestConfirmation::domain_)
            .def_readwrite("bot_user_id", &td_api::loginUrlInfoRequestConfirmation::bot_user_id_)
            .def_readwrite("request_write_access", &td_api::loginUrlInfoRequestConfirmation::request_write_access_);
    
    // Contains information about a message thread
    py::class_<td_api::messageThreadInfo>(m, "messageThreadInfo")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::messageThreadInfo::chat_id_)
            .def_readwrite("message_thread_id", &td_api::messageThreadInfo::message_thread_id_)
            .def_readwrite("reply_info", &td_api::messageThreadInfo::reply_info_)
            .def_readwrite("messages", &td_api::messageThreadInfo::messages_)
            .def_readwrite("draft_message", &td_api::messageThreadInfo::draft_message_);
    
    // A plain text @text Text
    py::class_<td_api::richTextPlain>(m, "richTextPlain")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextPlain::text_);
    
    // A bold rich text @text Text
    py::class_<td_api::richTextBold>(m, "richTextBold")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextBold::text_);
    
    // An italicized rich text @text Text
    py::class_<td_api::richTextItalic>(m, "richTextItalic")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextItalic::text_);
    
    // An underlined rich text @text Text
    py::class_<td_api::richTextUnderline>(m, "richTextUnderline")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextUnderline::text_);
    
    // A strikethrough rich text @text Text
    py::class_<td_api::richTextStrikethrough>(m, "richTextStrikethrough")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextStrikethrough::text_);
    
    // A fixed-width rich text @text Text
    py::class_<td_api::richTextFixed>(m, "richTextFixed")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextFixed::text_);
    
    // A rich text URL link @text Text @url URL @is_cached True, if the URL has cached instant view server-side
    py::class_<td_api::richTextUrl>(m, "richTextUrl")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextUrl::text_)
            .def_readwrite("url", &td_api::richTextUrl::url_)
            .def_readwrite("is_cached", &td_api::richTextUrl::is_cached_);
    
    // A rich text email link @text Text @email_address Email address
    py::class_<td_api::richTextEmailAddress>(m, "richTextEmailAddress")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextEmailAddress::text_)
            .def_readwrite("email_address", &td_api::richTextEmailAddress::email_address_);
    
    // A subscript rich text @text Text
    py::class_<td_api::richTextSubscript>(m, "richTextSubscript")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextSubscript::text_);
    
    // A superscript rich text @text Text
    py::class_<td_api::richTextSuperscript>(m, "richTextSuperscript")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextSuperscript::text_);
    
    // A marked rich text @text Text
    py::class_<td_api::richTextMarked>(m, "richTextMarked")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextMarked::text_);
    
    // A rich text phone number @text Text @phone_number Phone number
    py::class_<td_api::richTextPhoneNumber>(m, "richTextPhoneNumber")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextPhoneNumber::text_)
            .def_readwrite("phone_number", &td_api::richTextPhoneNumber::phone_number_);
    
    // A small image inside the text @document The image represented as a document. The image can be in GIF, JPEG or PNG format
    py::class_<td_api::richTextIcon>(m, "richTextIcon")
            .def(py::init<>())
    
            .def_readwrite("document", &td_api::richTextIcon::document_)
            .def_readwrite("width", &td_api::richTextIcon::width_)
            .def_readwrite("height", &td_api::richTextIcon::height_);
    
    // A reference to a richTexts object on the same web page @text The text @anchor_name The name of a richTextAnchor object, which is the first element of the target richTexts object @url An HTTP URL, opening the reference
    py::class_<td_api::richTextReference>(m, "richTextReference")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextReference::text_)
            .def_readwrite("anchor_name", &td_api::richTextReference::anchor_name_)
            .def_readwrite("url", &td_api::richTextReference::url_);
    
    // An anchor @name Anchor name
    py::class_<td_api::richTextAnchor>(m, "richTextAnchor")
            .def(py::init<>())
    
            .def_readwrite("name", &td_api::richTextAnchor::name_);
    
    // A link to an anchor on the same web page @text The link text @anchor_name The anchor name. If the name is empty, the link should bring back to top @url An HTTP URL, opening the anchor
    py::class_<td_api::richTextAnchorLink>(m, "richTextAnchorLink")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::richTextAnchorLink::text_)
            .def_readwrite("anchor_name", &td_api::richTextAnchorLink::anchor_name_)
            .def_readwrite("url", &td_api::richTextAnchorLink::url_);
    
    // A concatenation of rich texts @texts Texts
    py::class_<td_api::richTexts>(m, "richTexts")
            .def(py::init<>())
    
            .def_readwrite("texts", &td_api::richTexts::texts_);
    
    // Contains a caption of an instant view web page block, consisting of a text and a trailing credit @text Content of the caption @credit Block credit (like HTML tag <cite>)
    py::class_<td_api::pageBlockCaption>(m, "pageBlockCaption")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pageBlockCaption::text_)
            .def_readwrite("credit", &td_api::pageBlockCaption::credit_);
    
    // Describes an item of a list page block @label Item label @page_blocks Item blocks
    py::class_<td_api::pageBlockListItem>(m, "pageBlockListItem")
            .def(py::init<>())
    
            .def_readwrite("label", &td_api::pageBlockListItem::label_)
            .def_readwrite("page_blocks", &td_api::pageBlockListItem::page_blocks_);
    
    // The content should be left-aligned
    py::class_<td_api::pageBlockHorizontalAlignmentLeft>(m, "pageBlockHorizontalAlignmentLeft")
            .def(py::init<>());
    
    // The content should be center-aligned
    py::class_<td_api::pageBlockHorizontalAlignmentCenter>(m, "pageBlockHorizontalAlignmentCenter")
            .def(py::init<>());
    
    // The content should be right-aligned
    py::class_<td_api::pageBlockHorizontalAlignmentRight>(m, "pageBlockHorizontalAlignmentRight")
            .def(py::init<>());
    
    // The content should be top-aligned
    py::class_<td_api::pageBlockVerticalAlignmentTop>(m, "pageBlockVerticalAlignmentTop")
            .def(py::init<>());
    
    // The content should be middle-aligned
    py::class_<td_api::pageBlockVerticalAlignmentMiddle>(m, "pageBlockVerticalAlignmentMiddle")
            .def(py::init<>());
    
    // The content should be bottom-aligned
    py::class_<td_api::pageBlockVerticalAlignmentBottom>(m, "pageBlockVerticalAlignmentBottom")
            .def(py::init<>());
    
    // Represents a cell of a table @text Cell text; may be null. If the text is null, then the cell should be invisible @is_header True, if it is a header cell
    py::class_<td_api::pageBlockTableCell>(m, "pageBlockTableCell")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pageBlockTableCell::text_)
            .def_readwrite("is_header", &td_api::pageBlockTableCell::is_header_)
            .def_readwrite("colspan", &td_api::pageBlockTableCell::colspan_)
            .def_readwrite("rowspan", &td_api::pageBlockTableCell::rowspan_)
            .def_readwrite("align", &td_api::pageBlockTableCell::align_)
            .def_readwrite("valign", &td_api::pageBlockTableCell::valign_);
    
    // Contains information about a related article @url Related article URL @title Article title; may be empty @param_description Article description; may be empty
    py::class_<td_api::pageBlockRelatedArticle>(m, "pageBlockRelatedArticle")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::pageBlockRelatedArticle::url_)
            .def_readwrite("title", &td_api::pageBlockRelatedArticle::title_)
            .def_readwrite("description", &td_api::pageBlockRelatedArticle::description_)
            .def_readwrite("photo", &td_api::pageBlockRelatedArticle::photo_)
            .def_readwrite("author", &td_api::pageBlockRelatedArticle::author_)
            .def_readwrite("publish_date", &td_api::pageBlockRelatedArticle::publish_date_);
    
    // The title of a page @title Title
    py::class_<td_api::pageBlockTitle>(m, "pageBlockTitle")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::pageBlockTitle::title_);
    
    // The subtitle of a page @subtitle Subtitle
    py::class_<td_api::pageBlockSubtitle>(m, "pageBlockSubtitle")
            .def(py::init<>())
    
            .def_readwrite("subtitle", &td_api::pageBlockSubtitle::subtitle_);
    
    // The author and publishing date of a page @author Author @publish_date Point in time (Unix timestamp) when the article was published; 0 if unknown
    py::class_<td_api::pageBlockAuthorDate>(m, "pageBlockAuthorDate")
            .def(py::init<>())
    
            .def_readwrite("author", &td_api::pageBlockAuthorDate::author_)
            .def_readwrite("publish_date", &td_api::pageBlockAuthorDate::publish_date_);
    
    // A header @header Header
    py::class_<td_api::pageBlockHeader>(m, "pageBlockHeader")
            .def(py::init<>())
    
            .def_readwrite("header", &td_api::pageBlockHeader::header_);
    
    // A subheader @subheader Subheader
    py::class_<td_api::pageBlockSubheader>(m, "pageBlockSubheader")
            .def(py::init<>())
    
            .def_readwrite("subheader", &td_api::pageBlockSubheader::subheader_);
    
    // A kicker @kicker Kicker
    py::class_<td_api::pageBlockKicker>(m, "pageBlockKicker")
            .def(py::init<>())
    
            .def_readwrite("kicker", &td_api::pageBlockKicker::kicker_);
    
    // A text paragraph @text Paragraph text
    py::class_<td_api::pageBlockParagraph>(m, "pageBlockParagraph")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pageBlockParagraph::text_);
    
    // A preformatted text paragraph @text Paragraph text @language Programming language for which the text should be formatted
    py::class_<td_api::pageBlockPreformatted>(m, "pageBlockPreformatted")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pageBlockPreformatted::text_)
            .def_readwrite("language", &td_api::pageBlockPreformatted::language_);
    
    // The footer of a page @footer Footer
    py::class_<td_api::pageBlockFooter>(m, "pageBlockFooter")
            .def(py::init<>())
    
            .def_readwrite("footer", &td_api::pageBlockFooter::footer_);
    
    // An empty block separating a page
    py::class_<td_api::pageBlockDivider>(m, "pageBlockDivider")
            .def(py::init<>());
    
    // An invisible anchor on a page, which can be used in a URL to open the page from the specified anchor @name Name of the anchor
    py::class_<td_api::pageBlockAnchor>(m, "pageBlockAnchor")
            .def(py::init<>())
    
            .def_readwrite("name", &td_api::pageBlockAnchor::name_);
    
    // A list of data blocks @items The items of the list
    py::class_<td_api::pageBlockList>(m, "pageBlockList")
            .def(py::init<>())
    
            .def_readwrite("items", &td_api::pageBlockList::items_);
    
    // A block quote @text Quote text @credit Quote credit
    py::class_<td_api::pageBlockBlockQuote>(m, "pageBlockBlockQuote")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pageBlockBlockQuote::text_)
            .def_readwrite("credit", &td_api::pageBlockBlockQuote::credit_);
    
    // A pull quote @text Quote text @credit Quote credit
    py::class_<td_api::pageBlockPullQuote>(m, "pageBlockPullQuote")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pageBlockPullQuote::text_)
            .def_readwrite("credit", &td_api::pageBlockPullQuote::credit_);
    
    // An animation @animation Animation file; may be null @caption Animation caption @need_autoplay True, if the animation should be played automatically
    py::class_<td_api::pageBlockAnimation>(m, "pageBlockAnimation")
            .def(py::init<>())
    
            .def_readwrite("animation", &td_api::pageBlockAnimation::animation_)
            .def_readwrite("caption", &td_api::pageBlockAnimation::caption_)
            .def_readwrite("need_autoplay", &td_api::pageBlockAnimation::need_autoplay_);
    
    // An audio file @audio Audio file; may be null @caption Audio file caption
    py::class_<td_api::pageBlockAudio>(m, "pageBlockAudio")
            .def(py::init<>())
    
            .def_readwrite("audio", &td_api::pageBlockAudio::audio_)
            .def_readwrite("caption", &td_api::pageBlockAudio::caption_);
    
    // A photo @photo Photo file; may be null @caption Photo caption @url URL that needs to be opened when the photo is clicked
    py::class_<td_api::pageBlockPhoto>(m, "pageBlockPhoto")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::pageBlockPhoto::photo_)
            .def_readwrite("caption", &td_api::pageBlockPhoto::caption_)
            .def_readwrite("url", &td_api::pageBlockPhoto::url_);
    
    // A video @video Video file; may be null @caption Video caption @need_autoplay True, if the video should be played automatically @is_looped True, if the video should be looped
    py::class_<td_api::pageBlockVideo>(m, "pageBlockVideo")
            .def(py::init<>())
    
            .def_readwrite("video", &td_api::pageBlockVideo::video_)
            .def_readwrite("caption", &td_api::pageBlockVideo::caption_)
            .def_readwrite("need_autoplay", &td_api::pageBlockVideo::need_autoplay_)
            .def_readwrite("is_looped", &td_api::pageBlockVideo::is_looped_);
    
    // A voice note @voice_note Voice note; may be null @caption Voice note caption
    py::class_<td_api::pageBlockVoiceNote>(m, "pageBlockVoiceNote")
            .def(py::init<>())
    
            .def_readwrite("voice_note", &td_api::pageBlockVoiceNote::voice_note_)
            .def_readwrite("caption", &td_api::pageBlockVoiceNote::caption_);
    
    // A page cover @cover Cover
    py::class_<td_api::pageBlockCover>(m, "pageBlockCover")
            .def(py::init<>())
    
            .def_readwrite("cover", &td_api::pageBlockCover::cover_);
    
    // An embedded web page @url Web page URL, if available @html HTML-markup of the embedded page @poster_photo Poster photo, if available; may be null @width Block width; 0 if unknown @height Block height; 0 if unknown @caption Block caption @is_full_width True, if the block should be full width @allow_scrolling True, if scrolling should be allowed
    py::class_<td_api::pageBlockEmbedded>(m, "pageBlockEmbedded")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::pageBlockEmbedded::url_)
            .def_readwrite("html", &td_api::pageBlockEmbedded::html_)
            .def_readwrite("poster_photo", &td_api::pageBlockEmbedded::poster_photo_)
            .def_readwrite("width", &td_api::pageBlockEmbedded::width_)
            .def_readwrite("height", &td_api::pageBlockEmbedded::height_)
            .def_readwrite("caption", &td_api::pageBlockEmbedded::caption_)
            .def_readwrite("is_full_width", &td_api::pageBlockEmbedded::is_full_width_)
            .def_readwrite("allow_scrolling", &td_api::pageBlockEmbedded::allow_scrolling_);
    
    // An embedded post @url Web page URL @author Post author @author_photo Post author photo; may be null @date Point in time (Unix timestamp) when the post was created; 0 if unknown @page_blocks Post content @caption Post caption
    py::class_<td_api::pageBlockEmbeddedPost>(m, "pageBlockEmbeddedPost")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::pageBlockEmbeddedPost::url_)
            .def_readwrite("author", &td_api::pageBlockEmbeddedPost::author_)
            .def_readwrite("author_photo", &td_api::pageBlockEmbeddedPost::author_photo_)
            .def_readwrite("date", &td_api::pageBlockEmbeddedPost::date_)
            .def_readwrite("page_blocks", &td_api::pageBlockEmbeddedPost::page_blocks_)
            .def_readwrite("caption", &td_api::pageBlockEmbeddedPost::caption_);
    
    // A collage @page_blocks Collage item contents @caption Block caption
    py::class_<td_api::pageBlockCollage>(m, "pageBlockCollage")
            .def(py::init<>())
    
            .def_readwrite("page_blocks", &td_api::pageBlockCollage::page_blocks_)
            .def_readwrite("caption", &td_api::pageBlockCollage::caption_);
    
    // A slideshow @page_blocks Slideshow item contents @caption Block caption
    py::class_<td_api::pageBlockSlideshow>(m, "pageBlockSlideshow")
            .def(py::init<>())
    
            .def_readwrite("page_blocks", &td_api::pageBlockSlideshow::page_blocks_)
            .def_readwrite("caption", &td_api::pageBlockSlideshow::caption_);
    
    // A link to a chat @title Chat title @photo Chat photo; may be null @username Chat username, by which all other information about the chat should be resolved
    py::class_<td_api::pageBlockChatLink>(m, "pageBlockChatLink")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::pageBlockChatLink::title_)
            .def_readwrite("photo", &td_api::pageBlockChatLink::photo_)
            .def_readwrite("username", &td_api::pageBlockChatLink::username_);
    
    // A table @caption Table caption @cells Table cells @is_bordered True, if the table is bordered @is_striped True, if the table is striped
    py::class_<td_api::pageBlockTable>(m, "pageBlockTable")
            .def(py::init<>())
    
            .def_readwrite("caption", &td_api::pageBlockTable::caption_)
            .def_readwrite("cells", &td_api::pageBlockTable::cells_)
            .def_readwrite("is_bordered", &td_api::pageBlockTable::is_bordered_)
            .def_readwrite("is_striped", &td_api::pageBlockTable::is_striped_);
    
    // A collapsible block @header Always visible heading for the block @page_blocks Block contents @is_open True, if the block is open by default
    py::class_<td_api::pageBlockDetails>(m, "pageBlockDetails")
            .def(py::init<>())
    
            .def_readwrite("header", &td_api::pageBlockDetails::header_)
            .def_readwrite("page_blocks", &td_api::pageBlockDetails::page_blocks_)
            .def_readwrite("is_open", &td_api::pageBlockDetails::is_open_);
    
    // Related articles @header Block header @articles List of related articles
    py::class_<td_api::pageBlockRelatedArticles>(m, "pageBlockRelatedArticles")
            .def(py::init<>())
    
            .def_readwrite("header", &td_api::pageBlockRelatedArticles::header_)
            .def_readwrite("articles", &td_api::pageBlockRelatedArticles::articles_);
    
    // A map @location Location of the map center @zoom Map zoom level @width Map width @height Map height @caption Block caption
    py::class_<td_api::pageBlockMap>(m, "pageBlockMap")
            .def(py::init<>())
    
            .def_readwrite("location", &td_api::pageBlockMap::location_)
            .def_readwrite("zoom", &td_api::pageBlockMap::zoom_)
            .def_readwrite("width", &td_api::pageBlockMap::width_)
            .def_readwrite("height", &td_api::pageBlockMap::height_)
            .def_readwrite("caption", &td_api::pageBlockMap::caption_);
    
    // Describes an instant view page for a web page
    py::class_<td_api::webPageInstantView>(m, "webPageInstantView")
            .def(py::init<>())
    
            .def_readwrite("page_blocks", &td_api::webPageInstantView::page_blocks_)
            .def_readwrite("view_count", &td_api::webPageInstantView::view_count_)
            .def_readwrite("version", &td_api::webPageInstantView::version_)
            .def_readwrite("is_rtl", &td_api::webPageInstantView::is_rtl_)
            .def_readwrite("is_full", &td_api::webPageInstantView::is_full_);
    
    // Describes a web page preview
    py::class_<td_api::webPage>(m, "webPage")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::webPage::url_)
            .def_readwrite("display_url", &td_api::webPage::display_url_)
            .def_readwrite("type", &td_api::webPage::type_)
            .def_readwrite("site_name", &td_api::webPage::site_name_)
            .def_readwrite("title", &td_api::webPage::title_)
            .def_readwrite("description", &td_api::webPage::description_)
            .def_readwrite("photo", &td_api::webPage::photo_)
            .def_readwrite("embed_url", &td_api::webPage::embed_url_)
            .def_readwrite("embed_type", &td_api::webPage::embed_type_)
            .def_readwrite("embed_width", &td_api::webPage::embed_width_)
            .def_readwrite("embed_height", &td_api::webPage::embed_height_)
            .def_readwrite("duration", &td_api::webPage::duration_)
            .def_readwrite("author", &td_api::webPage::author_)
            .def_readwrite("animation", &td_api::webPage::animation_)
            .def_readwrite("audio", &td_api::webPage::audio_)
            .def_readwrite("document", &td_api::webPage::document_)
            .def_readwrite("sticker", &td_api::webPage::sticker_)
            .def_readwrite("video", &td_api::webPage::video_)
            .def_readwrite("video_note", &td_api::webPage::video_note_)
            .def_readwrite("voice_note", &td_api::webPage::voice_note_)
            .def_readwrite("instant_view_version", &td_api::webPage::instant_view_version_);
    
    // Contains information about a country
    py::class_<td_api::countryInfo>(m, "countryInfo")
            .def(py::init<>())
    
            .def_readwrite("country_code", &td_api::countryInfo::country_code_)
            .def_readwrite("name", &td_api::countryInfo::name_)
            .def_readwrite("english_name", &td_api::countryInfo::english_name_)
            .def_readwrite("is_hidden", &td_api::countryInfo::is_hidden_)
            .def_readwrite("calling_codes", &td_api::countryInfo::calling_codes_);
    
    // Contains information about countries @countries The list of countries
    py::class_<td_api::countries>(m, "countries")
            .def(py::init<>())
    
            .def_readwrite("countries", &td_api::countries::countries_);
    
    // Contains information about a phone number
    py::class_<td_api::phoneNumberInfo>(m, "phoneNumberInfo")
            .def(py::init<>())
    
            .def_readwrite("country", &td_api::phoneNumberInfo::country_)
            .def_readwrite("country_calling_code", &td_api::phoneNumberInfo::country_calling_code_)
            .def_readwrite("formatted_phone_number", &td_api::phoneNumberInfo::formatted_phone_number_);
    
    // Describes an action associated with a bank card number @text Action text @url The URL to be opened
    py::class_<td_api::bankCardActionOpenUrl>(m, "bankCardActionOpenUrl")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::bankCardActionOpenUrl::text_)
            .def_readwrite("url", &td_api::bankCardActionOpenUrl::url_);
    
    // Information about a bank card @title Title of the bank card description @actions Actions that can be done with the bank card number
    py::class_<td_api::bankCardInfo>(m, "bankCardInfo")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::bankCardInfo::title_)
            .def_readwrite("actions", &td_api::bankCardInfo::actions_);
    
    // Describes an address @country_code A two-letter ISO 3166-1 alpha-2 country code @state State, if applicable @city City @street_line1 First line of the address @street_line2 Second line of the address @postal_code Address postal code
    py::class_<td_api::address>(m, "address")
            .def(py::init<>())
    
            .def_readwrite("country_code", &td_api::address::country_code_)
            .def_readwrite("state", &td_api::address::state_)
            .def_readwrite("city", &td_api::address::city_)
            .def_readwrite("street_line1", &td_api::address::street_line1_)
            .def_readwrite("street_line2", &td_api::address::street_line2_)
            .def_readwrite("postal_code", &td_api::address::postal_code_);
    
    // Portion of the price of a product (e.g., "delivery cost", "tax amount") @label Label for this portion of the product price @amount Currency amount in the smallest units of the currency
    py::class_<td_api::labeledPricePart>(m, "labeledPricePart")
            .def(py::init<>())
    
            .def_readwrite("label", &td_api::labeledPricePart::label_)
            .def_readwrite("amount", &td_api::labeledPricePart::amount_);
    
    // Product invoice @currency ISO 4217 currency code
    py::class_<td_api::invoice>(m, "invoice")
            .def(py::init<>())
    
            .def_readwrite("currency", &td_api::invoice::currency_)
            .def_readwrite("price_parts", &td_api::invoice::price_parts_)
            .def_readwrite("max_tip_amount", &td_api::invoice::max_tip_amount_)
            .def_readwrite("suggested_tip_amounts", &td_api::invoice::suggested_tip_amounts_)
            .def_readwrite("is_test", &td_api::invoice::is_test_)
            .def_readwrite("need_name", &td_api::invoice::need_name_)
            .def_readwrite("need_phone_number", &td_api::invoice::need_phone_number_)
            .def_readwrite("need_email_address", &td_api::invoice::need_email_address_)
            .def_readwrite("need_shipping_address", &td_api::invoice::need_shipping_address_)
            .def_readwrite("send_phone_number_to_provider", &td_api::invoice::send_phone_number_to_provider_)
            .def_readwrite("send_email_address_to_provider", &td_api::invoice::send_email_address_to_provider_)
            .def_readwrite("is_flexible", &td_api::invoice::is_flexible_);
    
    // Order information @name Name of the user @phone_number Phone number of the user @email_address Email address of the user @shipping_address Shipping address for this order; may be null
    py::class_<td_api::orderInfo>(m, "orderInfo")
            .def(py::init<>())
    
            .def_readwrite("name", &td_api::orderInfo::name_)
            .def_readwrite("phone_number", &td_api::orderInfo::phone_number_)
            .def_readwrite("email_address", &td_api::orderInfo::email_address_)
            .def_readwrite("shipping_address", &td_api::orderInfo::shipping_address_);
    
    // One shipping option @id Shipping option identifier @title Option title @price_parts A list of objects used to calculate the total shipping costs
    py::class_<td_api::shippingOption>(m, "shippingOption")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::shippingOption::id_)
            .def_readwrite("title", &td_api::shippingOption::title_)
            .def_readwrite("price_parts", &td_api::shippingOption::price_parts_);
    
    // Contains information about saved card credentials @id Unique identifier of the saved credentials @title Title of the saved credentials
    py::class_<td_api::savedCredentials>(m, "savedCredentials")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::savedCredentials::id_)
            .def_readwrite("title", &td_api::savedCredentials::title_);
    
    // Applies if a user chooses some previously saved payment credentials. To use their previously saved credentials, the user must have a valid temporary password @saved_credentials_id Identifier of the saved credentials
    py::class_<td_api::inputCredentialsSaved>(m, "inputCredentialsSaved")
            .def(py::init<>())
    
            .def_readwrite("saved_credentials_id", &td_api::inputCredentialsSaved::saved_credentials_id_);
    
    // Applies if a user enters new credentials on a payment provider website @data Contains JSON-encoded data with a credential identifier from the payment provider @allow_save True, if the credential identifier can be saved on the server side
    py::class_<td_api::inputCredentialsNew>(m, "inputCredentialsNew")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::inputCredentialsNew::data_)
            .def_readwrite("allow_save", &td_api::inputCredentialsNew::allow_save_);
    
    // Applies if a user enters new credentials using Apple Pay @data JSON-encoded data with the credential identifier
    py::class_<td_api::inputCredentialsApplePay>(m, "inputCredentialsApplePay")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::inputCredentialsApplePay::data_);
    
    // Applies if a user enters new credentials using Google Pay @data JSON-encoded data with the credential identifier
    py::class_<td_api::inputCredentialsGooglePay>(m, "inputCredentialsGooglePay")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::inputCredentialsGooglePay::data_);
    
    // Stripe payment provider @publishable_key Stripe API publishable key @need_country True, if the user country must be provided @need_postal_code True, if the user ZIP/postal code must be provided @need_cardholder_name True, if the cardholder name must be provided
    py::class_<td_api::paymentsProviderStripe>(m, "paymentsProviderStripe")
            .def(py::init<>())
    
            .def_readwrite("publishable_key", &td_api::paymentsProviderStripe::publishable_key_)
            .def_readwrite("need_country", &td_api::paymentsProviderStripe::need_country_)
            .def_readwrite("need_postal_code", &td_api::paymentsProviderStripe::need_postal_code_)
            .def_readwrite("need_cardholder_name", &td_api::paymentsProviderStripe::need_cardholder_name_);
    
    // Theme colors for a payment form @background_color A color of the payment form background in the RGB24 format @text_color A color of text in the RGB24 format
    py::class_<td_api::paymentFormTheme>(m, "paymentFormTheme")
            .def(py::init<>())
    
            .def_readwrite("background_color", &td_api::paymentFormTheme::background_color_)
            .def_readwrite("text_color", &td_api::paymentFormTheme::text_color_)
            .def_readwrite("hint_color", &td_api::paymentFormTheme::hint_color_)
            .def_readwrite("link_color", &td_api::paymentFormTheme::link_color_)
            .def_readwrite("button_color", &td_api::paymentFormTheme::button_color_)
            .def_readwrite("button_text_color", &td_api::paymentFormTheme::button_text_color_);
    
    // Contains information about an invoice payment form
    py::class_<td_api::paymentForm>(m, "paymentForm")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::paymentForm::id_)
            .def_readwrite("invoice", &td_api::paymentForm::invoice_)
            .def_readwrite("url", &td_api::paymentForm::url_)
            .def_readwrite("seller_bot_user_id", &td_api::paymentForm::seller_bot_user_id_)
            .def_readwrite("payments_provider_user_id", &td_api::paymentForm::payments_provider_user_id_)
            .def_readwrite("payments_provider", &td_api::paymentForm::payments_provider_)
            .def_readwrite("saved_order_info", &td_api::paymentForm::saved_order_info_)
            .def_readwrite("saved_credentials", &td_api::paymentForm::saved_credentials_)
            .def_readwrite("can_save_credentials", &td_api::paymentForm::can_save_credentials_)
            .def_readwrite("need_password", &td_api::paymentForm::need_password_);
    
    // Contains a temporary identifier of validated order information, which is stored for one hour. Also contains the available shipping options @order_info_id Temporary identifier of the order information @shipping_options Available shipping options
    py::class_<td_api::validatedOrderInfo>(m, "validatedOrderInfo")
            .def(py::init<>())
    
            .def_readwrite("order_info_id", &td_api::validatedOrderInfo::order_info_id_)
            .def_readwrite("shipping_options", &td_api::validatedOrderInfo::shipping_options_);
    
    // Contains the result of a payment request @success True, if the payment request was successful; otherwise the verification_url will be not empty @verification_url URL for additional payment credentials verification
    py::class_<td_api::paymentResult>(m, "paymentResult")
            .def(py::init<>())
    
            .def_readwrite("success", &td_api::paymentResult::success_)
            .def_readwrite("verification_url", &td_api::paymentResult::verification_url_);
    
    // Contains information about a successful payment
    py::class_<td_api::paymentReceipt>(m, "paymentReceipt")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::paymentReceipt::title_)
            .def_readwrite("description", &td_api::paymentReceipt::description_)
            .def_readwrite("photo", &td_api::paymentReceipt::photo_)
            .def_readwrite("date", &td_api::paymentReceipt::date_)
            .def_readwrite("seller_bot_user_id", &td_api::paymentReceipt::seller_bot_user_id_)
            .def_readwrite("payments_provider_user_id", &td_api::paymentReceipt::payments_provider_user_id_)
            .def_readwrite("invoice", &td_api::paymentReceipt::invoice_)
            .def_readwrite("order_info", &td_api::paymentReceipt::order_info_)
            .def_readwrite("shipping_option", &td_api::paymentReceipt::shipping_option_)
            .def_readwrite("credentials_title", &td_api::paymentReceipt::credentials_title_)
            .def_readwrite("tip_amount", &td_api::paymentReceipt::tip_amount_);
    
    // File with the date it was uploaded @file The file @date Point in time (Unix timestamp) when the file was uploaded
    py::class_<td_api::datedFile>(m, "datedFile")
            .def(py::init<>())
    
            .def_readwrite("file", &td_api::datedFile::file_)
            .def_readwrite("date", &td_api::datedFile::date_);
    
    // A Telegram Passport element containing the user's personal details
    py::class_<td_api::passportElementTypePersonalDetails>(m, "passportElementTypePersonalDetails")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's passport
    py::class_<td_api::passportElementTypePassport>(m, "passportElementTypePassport")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's driver license
    py::class_<td_api::passportElementTypeDriverLicense>(m, "passportElementTypeDriverLicense")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's identity card
    py::class_<td_api::passportElementTypeIdentityCard>(m, "passportElementTypeIdentityCard")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's internal passport
    py::class_<td_api::passportElementTypeInternalPassport>(m, "passportElementTypeInternalPassport")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's address
    py::class_<td_api::passportElementTypeAddress>(m, "passportElementTypeAddress")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's utility bill
    py::class_<td_api::passportElementTypeUtilityBill>(m, "passportElementTypeUtilityBill")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's bank statement
    py::class_<td_api::passportElementTypeBankStatement>(m, "passportElementTypeBankStatement")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's rental agreement
    py::class_<td_api::passportElementTypeRentalAgreement>(m, "passportElementTypeRentalAgreement")
            .def(py::init<>());
    
    // A Telegram Passport element containing the registration page of the user's passport
    py::class_<td_api::passportElementTypePassportRegistration>(m, "passportElementTypePassportRegistration")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's temporary registration
    py::class_<td_api::passportElementTypeTemporaryRegistration>(m, "passportElementTypeTemporaryRegistration")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's phone number
    py::class_<td_api::passportElementTypePhoneNumber>(m, "passportElementTypePhoneNumber")
            .def(py::init<>());
    
    // A Telegram Passport element containing the user's email address
    py::class_<td_api::passportElementTypeEmailAddress>(m, "passportElementTypeEmailAddress")
            .def(py::init<>());
    
    // Represents a date according to the Gregorian calendar @day Day of the month; 1-31 @month Month; 1-12 @year Year; 1-9999
    py::class_<td_api::date>(m, "date")
            .def(py::init<>())
    
            .def_readwrite("day", &td_api::date::day_)
            .def_readwrite("month", &td_api::date::month_)
            .def_readwrite("year", &td_api::date::year_);
    
    // Contains the user's personal details
    py::class_<td_api::personalDetails>(m, "personalDetails")
            .def(py::init<>())
    
            .def_readwrite("first_name", &td_api::personalDetails::first_name_)
            .def_readwrite("middle_name", &td_api::personalDetails::middle_name_)
            .def_readwrite("last_name", &td_api::personalDetails::last_name_)
            .def_readwrite("native_first_name", &td_api::personalDetails::native_first_name_)
            .def_readwrite("native_middle_name", &td_api::personalDetails::native_middle_name_)
            .def_readwrite("native_last_name", &td_api::personalDetails::native_last_name_)
            .def_readwrite("birthdate", &td_api::personalDetails::birthdate_)
            .def_readwrite("gender", &td_api::personalDetails::gender_)
            .def_readwrite("country_code", &td_api::personalDetails::country_code_)
            .def_readwrite("residence_country_code", &td_api::personalDetails::residence_country_code_);
    
    // An identity document @number Document number; 1-24 characters @expiry_date Document expiry date; may be null @front_side Front side of the document
    py::class_<td_api::identityDocument>(m, "identityDocument")
            .def(py::init<>())
    
            .def_readwrite("number", &td_api::identityDocument::number_)
            .def_readwrite("expiry_date", &td_api::identityDocument::expiry_date_)
            .def_readwrite("front_side", &td_api::identityDocument::front_side_)
            .def_readwrite("reverse_side", &td_api::identityDocument::reverse_side_)
            .def_readwrite("selfie", &td_api::identityDocument::selfie_)
            .def_readwrite("translation", &td_api::identityDocument::translation_);
    
    // An identity document to be saved to Telegram Passport @number Document number; 1-24 characters @expiry_date Document expiry date, if available @front_side Front side of the document
    py::class_<td_api::inputIdentityDocument>(m, "inputIdentityDocument")
            .def(py::init<>())
    
            .def_readwrite("number", &td_api::inputIdentityDocument::number_)
            .def_readwrite("expiry_date", &td_api::inputIdentityDocument::expiry_date_)
            .def_readwrite("front_side", &td_api::inputIdentityDocument::front_side_)
            .def_readwrite("reverse_side", &td_api::inputIdentityDocument::reverse_side_)
            .def_readwrite("selfie", &td_api::inputIdentityDocument::selfie_)
            .def_readwrite("translation", &td_api::inputIdentityDocument::translation_);
    
    // A personal document, containing some information about a user @files List of files containing the pages of the document @translation List of files containing a certified English translation of the document
    py::class_<td_api::personalDocument>(m, "personalDocument")
            .def(py::init<>())
    
            .def_readwrite("files", &td_api::personalDocument::files_)
            .def_readwrite("translation", &td_api::personalDocument::translation_);
    
    // A personal document to be saved to Telegram Passport @files List of files containing the pages of the document @translation List of files containing a certified English translation of the document
    py::class_<td_api::inputPersonalDocument>(m, "inputPersonalDocument")
            .def(py::init<>())
    
            .def_readwrite("files", &td_api::inputPersonalDocument::files_)
            .def_readwrite("translation", &td_api::inputPersonalDocument::translation_);
    
    // A Telegram Passport element containing the user's personal details @personal_details Personal details of the user
    py::class_<td_api::passportElementPersonalDetails>(m, "passportElementPersonalDetails")
            .def(py::init<>())
    
            .def_readwrite("personal_details", &td_api::passportElementPersonalDetails::personal_details_);
    
    // A Telegram Passport element containing the user's passport @passport Passport
    py::class_<td_api::passportElementPassport>(m, "passportElementPassport")
            .def(py::init<>())
    
            .def_readwrite("passport", &td_api::passportElementPassport::passport_);
    
    // A Telegram Passport element containing the user's driver license @driver_license Driver license
    py::class_<td_api::passportElementDriverLicense>(m, "passportElementDriverLicense")
            .def(py::init<>())
    
            .def_readwrite("driver_license", &td_api::passportElementDriverLicense::driver_license_);
    
    // A Telegram Passport element containing the user's identity card @identity_card Identity card
    py::class_<td_api::passportElementIdentityCard>(m, "passportElementIdentityCard")
            .def(py::init<>())
    
            .def_readwrite("identity_card", &td_api::passportElementIdentityCard::identity_card_);
    
    // A Telegram Passport element containing the user's internal passport @internal_passport Internal passport
    py::class_<td_api::passportElementInternalPassport>(m, "passportElementInternalPassport")
            .def(py::init<>())
    
            .def_readwrite("internal_passport", &td_api::passportElementInternalPassport::internal_passport_);
    
    // A Telegram Passport element containing the user's address @address Address
    py::class_<td_api::passportElementAddress>(m, "passportElementAddress")
            .def(py::init<>())
    
            .def_readwrite("address", &td_api::passportElementAddress::address_);
    
    // A Telegram Passport element containing the user's utility bill @utility_bill Utility bill
    py::class_<td_api::passportElementUtilityBill>(m, "passportElementUtilityBill")
            .def(py::init<>())
    
            .def_readwrite("utility_bill", &td_api::passportElementUtilityBill::utility_bill_);
    
    // A Telegram Passport element containing the user's bank statement @bank_statement Bank statement
    py::class_<td_api::passportElementBankStatement>(m, "passportElementBankStatement")
            .def(py::init<>())
    
            .def_readwrite("bank_statement", &td_api::passportElementBankStatement::bank_statement_);
    
    // A Telegram Passport element containing the user's rental agreement @rental_agreement Rental agreement
    py::class_<td_api::passportElementRentalAgreement>(m, "passportElementRentalAgreement")
            .def(py::init<>())
    
            .def_readwrite("rental_agreement", &td_api::passportElementRentalAgreement::rental_agreement_);
    
    // A Telegram Passport element containing the user's passport registration pages @passport_registration Passport registration pages
    py::class_<td_api::passportElementPassportRegistration>(m, "passportElementPassportRegistration")
            .def(py::init<>())
    
            .def_readwrite("passport_registration", &td_api::passportElementPassportRegistration::passport_registration_);
    
    // A Telegram Passport element containing the user's temporary registration @temporary_registration Temporary registration
    py::class_<td_api::passportElementTemporaryRegistration>(m, "passportElementTemporaryRegistration")
            .def(py::init<>())
    
            .def_readwrite("temporary_registration", &td_api::passportElementTemporaryRegistration::temporary_registration_);
    
    // A Telegram Passport element containing the user's phone number @phone_number Phone number
    py::class_<td_api::passportElementPhoneNumber>(m, "passportElementPhoneNumber")
            .def(py::init<>())
    
            .def_readwrite("phone_number", &td_api::passportElementPhoneNumber::phone_number_);
    
    // A Telegram Passport element containing the user's email address @email_address Email address
    py::class_<td_api::passportElementEmailAddress>(m, "passportElementEmailAddress")
            .def(py::init<>())
    
            .def_readwrite("email_address", &td_api::passportElementEmailAddress::email_address_);
    
    // A Telegram Passport element to be saved containing the user's personal details @personal_details Personal details of the user
    py::class_<td_api::inputPassportElementPersonalDetails>(m, "inputPassportElementPersonalDetails")
            .def(py::init<>())
    
            .def_readwrite("personal_details", &td_api::inputPassportElementPersonalDetails::personal_details_);
    
    // A Telegram Passport element to be saved containing the user's passport @passport The passport to be saved
    py::class_<td_api::inputPassportElementPassport>(m, "inputPassportElementPassport")
            .def(py::init<>())
    
            .def_readwrite("passport", &td_api::inputPassportElementPassport::passport_);
    
    // A Telegram Passport element to be saved containing the user's driver license @driver_license The driver license to be saved
    py::class_<td_api::inputPassportElementDriverLicense>(m, "inputPassportElementDriverLicense")
            .def(py::init<>())
    
            .def_readwrite("driver_license", &td_api::inputPassportElementDriverLicense::driver_license_);
    
    // A Telegram Passport element to be saved containing the user's identity card @identity_card The identity card to be saved
    py::class_<td_api::inputPassportElementIdentityCard>(m, "inputPassportElementIdentityCard")
            .def(py::init<>())
    
            .def_readwrite("identity_card", &td_api::inputPassportElementIdentityCard::identity_card_);
    
    // A Telegram Passport element to be saved containing the user's internal passport @internal_passport The internal passport to be saved
    py::class_<td_api::inputPassportElementInternalPassport>(m, "inputPassportElementInternalPassport")
            .def(py::init<>())
    
            .def_readwrite("internal_passport", &td_api::inputPassportElementInternalPassport::internal_passport_);
    
    // A Telegram Passport element to be saved containing the user's address @address The address to be saved
    py::class_<td_api::inputPassportElementAddress>(m, "inputPassportElementAddress")
            .def(py::init<>())
    
            .def_readwrite("address", &td_api::inputPassportElementAddress::address_);
    
    // A Telegram Passport element to be saved containing the user's utility bill @utility_bill The utility bill to be saved
    py::class_<td_api::inputPassportElementUtilityBill>(m, "inputPassportElementUtilityBill")
            .def(py::init<>())
    
            .def_readwrite("utility_bill", &td_api::inputPassportElementUtilityBill::utility_bill_);
    
    // A Telegram Passport element to be saved containing the user's bank statement @bank_statement The bank statement to be saved
    py::class_<td_api::inputPassportElementBankStatement>(m, "inputPassportElementBankStatement")
            .def(py::init<>())
    
            .def_readwrite("bank_statement", &td_api::inputPassportElementBankStatement::bank_statement_);
    
    // A Telegram Passport element to be saved containing the user's rental agreement @rental_agreement The rental agreement to be saved
    py::class_<td_api::inputPassportElementRentalAgreement>(m, "inputPassportElementRentalAgreement")
            .def(py::init<>())
    
            .def_readwrite("rental_agreement", &td_api::inputPassportElementRentalAgreement::rental_agreement_);
    
    // A Telegram Passport element to be saved containing the user's passport registration @passport_registration The passport registration page to be saved
    py::class_<td_api::inputPassportElementPassportRegistration>(m, "inputPassportElementPassportRegistration")
            .def(py::init<>())
    
            .def_readwrite("passport_registration", &td_api::inputPassportElementPassportRegistration::passport_registration_);
    
    // A Telegram Passport element to be saved containing the user's temporary registration @temporary_registration The temporary registration document to be saved
    py::class_<td_api::inputPassportElementTemporaryRegistration>(m, "inputPassportElementTemporaryRegistration")
            .def(py::init<>())
    
            .def_readwrite("temporary_registration", &td_api::inputPassportElementTemporaryRegistration::temporary_registration_);
    
    // A Telegram Passport element to be saved containing the user's phone number @phone_number The phone number to be saved
    py::class_<td_api::inputPassportElementPhoneNumber>(m, "inputPassportElementPhoneNumber")
            .def(py::init<>())
    
            .def_readwrite("phone_number", &td_api::inputPassportElementPhoneNumber::phone_number_);
    
    // A Telegram Passport element to be saved containing the user's email address @email_address The email address to be saved
    py::class_<td_api::inputPassportElementEmailAddress>(m, "inputPassportElementEmailAddress")
            .def(py::init<>())
    
            .def_readwrite("email_address", &td_api::inputPassportElementEmailAddress::email_address_);
    
    // Contains information about saved Telegram Passport elements @elements Telegram Passport elements
    py::class_<td_api::passportElements>(m, "passportElements")
            .def(py::init<>())
    
            .def_readwrite("elements", &td_api::passportElements::elements_);
    
    // The element contains an error in an unspecified place. The error will be considered resolved when new data is added
    py::class_<td_api::passportElementErrorSourceUnspecified>(m, "passportElementErrorSourceUnspecified")
            .def(py::init<>());
    
    // One of the data fields contains an error. The error will be considered resolved when the value of the field changes @field_name Field name
    py::class_<td_api::passportElementErrorSourceDataField>(m, "passportElementErrorSourceDataField")
            .def(py::init<>())
    
            .def_readwrite("field_name", &td_api::passportElementErrorSourceDataField::field_name_);
    
    // The front side of the document contains an error. The error will be considered resolved when the file with the front side changes
    py::class_<td_api::passportElementErrorSourceFrontSide>(m, "passportElementErrorSourceFrontSide")
            .def(py::init<>());
    
    // The reverse side of the document contains an error. The error will be considered resolved when the file with the reverse side changes
    py::class_<td_api::passportElementErrorSourceReverseSide>(m, "passportElementErrorSourceReverseSide")
            .def(py::init<>());
    
    // The selfie with the document contains an error. The error will be considered resolved when the file with the selfie changes
    py::class_<td_api::passportElementErrorSourceSelfie>(m, "passportElementErrorSourceSelfie")
            .def(py::init<>());
    
    // One of files with the translation of the document contains an error. The error will be considered resolved when the file changes @file_index Index of a file with the error
    py::class_<td_api::passportElementErrorSourceTranslationFile>(m, "passportElementErrorSourceTranslationFile")
            .def(py::init<>())
    
            .def_readwrite("file_index", &td_api::passportElementErrorSourceTranslationFile::file_index_);
    
    // The translation of the document contains an error. The error will be considered resolved when the list of translation files changes
    py::class_<td_api::passportElementErrorSourceTranslationFiles>(m, "passportElementErrorSourceTranslationFiles")
            .def(py::init<>());
    
    // The file contains an error. The error will be considered resolved when the file changes @file_index Index of a file with the error
    py::class_<td_api::passportElementErrorSourceFile>(m, "passportElementErrorSourceFile")
            .def(py::init<>())
    
            .def_readwrite("file_index", &td_api::passportElementErrorSourceFile::file_index_);
    
    // The list of attached files contains an error. The error will be considered resolved when the list of files changes
    py::class_<td_api::passportElementErrorSourceFiles>(m, "passportElementErrorSourceFiles")
            .def(py::init<>());
    
    // Contains the description of an error in a Telegram Passport element @type Type of the Telegram Passport element which has the error @message Error message @source Error source
    py::class_<td_api::passportElementError>(m, "passportElementError")
            .def(py::init<>())
    
            .def_readwrite("type", &td_api::passportElementError::type_)
            .def_readwrite("message", &td_api::passportElementError::message_)
            .def_readwrite("source", &td_api::passportElementError::source_);
    
    // Contains information about a Telegram Passport element that was requested by a service @type Type of the element @is_selfie_required True, if a selfie is required with the identity document
    py::class_<td_api::passportSuitableElement>(m, "passportSuitableElement")
            .def(py::init<>())
    
            .def_readwrite("type", &td_api::passportSuitableElement::type_)
            .def_readwrite("is_selfie_required", &td_api::passportSuitableElement::is_selfie_required_)
            .def_readwrite("is_translation_required", &td_api::passportSuitableElement::is_translation_required_)
            .def_readwrite("is_native_name_required", &td_api::passportSuitableElement::is_native_name_required_);
    
    // Contains a description of the required Telegram Passport element that was requested by a service @suitable_elements List of Telegram Passport elements any of which is enough to provide
    py::class_<td_api::passportRequiredElement>(m, "passportRequiredElement")
            .def(py::init<>())
    
            .def_readwrite("suitable_elements", &td_api::passportRequiredElement::suitable_elements_);
    
    // Contains information about a Telegram Passport authorization form that was requested @id Unique identifier of the authorization form
    py::class_<td_api::passportAuthorizationForm>(m, "passportAuthorizationForm")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::passportAuthorizationForm::id_)
            .def_readwrite("required_elements", &td_api::passportAuthorizationForm::required_elements_)
            .def_readwrite("privacy_policy_url", &td_api::passportAuthorizationForm::privacy_policy_url_);
    
    // Contains information about a Telegram Passport elements and corresponding errors @elements Telegram Passport elements @errors Errors in the elements that are already available
    py::class_<td_api::passportElementsWithErrors>(m, "passportElementsWithErrors")
            .def(py::init<>())
    
            .def_readwrite("elements", &td_api::passportElementsWithErrors::elements_)
            .def_readwrite("errors", &td_api::passportElementsWithErrors::errors_);
    
    // Contains encrypted Telegram Passport data credentials @data The encrypted credentials @hash The decrypted data hash @secret Secret for data decryption, encrypted with the service's public key
    py::class_<td_api::encryptedCredentials>(m, "encryptedCredentials")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::encryptedCredentials::data_)
            .def_readwrite("hash", &td_api::encryptedCredentials::hash_)
            .def_readwrite("secret", &td_api::encryptedCredentials::secret_);
    
    // Contains information about an encrypted Telegram Passport element; for bots only @type Type of Telegram Passport element @data Encrypted JSON-encoded data about the user @front_side The front side of an identity document @reverse_side The reverse side of an identity document; may be null @selfie Selfie with the document; may be null @translation List of files containing a certified English translation of the document @files List of attached files @value Unencrypted data, phone number or email address @hash Hash of the entire element
    py::class_<td_api::encryptedPassportElement>(m, "encryptedPassportElement")
            .def(py::init<>())
    
            .def_readwrite("type", &td_api::encryptedPassportElement::type_)
            .def_readwrite("data", &td_api::encryptedPassportElement::data_)
            .def_readwrite("front_side", &td_api::encryptedPassportElement::front_side_)
            .def_readwrite("reverse_side", &td_api::encryptedPassportElement::reverse_side_)
            .def_readwrite("selfie", &td_api::encryptedPassportElement::selfie_)
            .def_readwrite("translation", &td_api::encryptedPassportElement::translation_)
            .def_readwrite("files", &td_api::encryptedPassportElement::files_)
            .def_readwrite("value", &td_api::encryptedPassportElement::value_)
            .def_readwrite("hash", &td_api::encryptedPassportElement::hash_);
    
    // The element contains an error in an unspecified place. The error will be considered resolved when new data is added @element_hash Current hash of the entire element
    py::class_<td_api::inputPassportElementErrorSourceUnspecified>(m, "inputPassportElementErrorSourceUnspecified")
            .def(py::init<>())
    
            .def_readwrite("element_hash", &td_api::inputPassportElementErrorSourceUnspecified::element_hash_);
    
    // A data field contains an error. The error is considered resolved when the field's value changes @field_name Field name @data_hash Current data hash
    py::class_<td_api::inputPassportElementErrorSourceDataField>(m, "inputPassportElementErrorSourceDataField")
            .def(py::init<>())
    
            .def_readwrite("field_name", &td_api::inputPassportElementErrorSourceDataField::field_name_)
            .def_readwrite("data_hash", &td_api::inputPassportElementErrorSourceDataField::data_hash_);
    
    // The front side of the document contains an error. The error is considered resolved when the file with the front side of the document changes @file_hash Current hash of the file containing the front side
    py::class_<td_api::inputPassportElementErrorSourceFrontSide>(m, "inputPassportElementErrorSourceFrontSide")
            .def(py::init<>())
    
            .def_readwrite("file_hash", &td_api::inputPassportElementErrorSourceFrontSide::file_hash_);
    
    // The reverse side of the document contains an error. The error is considered resolved when the file with the reverse side of the document changes @file_hash Current hash of the file containing the reverse side
    py::class_<td_api::inputPassportElementErrorSourceReverseSide>(m, "inputPassportElementErrorSourceReverseSide")
            .def(py::init<>())
    
            .def_readwrite("file_hash", &td_api::inputPassportElementErrorSourceReverseSide::file_hash_);
    
    // The selfie contains an error. The error is considered resolved when the file with the selfie changes @file_hash Current hash of the file containing the selfie
    py::class_<td_api::inputPassportElementErrorSourceSelfie>(m, "inputPassportElementErrorSourceSelfie")
            .def(py::init<>())
    
            .def_readwrite("file_hash", &td_api::inputPassportElementErrorSourceSelfie::file_hash_);
    
    // One of the files containing the translation of the document contains an error. The error is considered resolved when the file with the translation changes @file_hash Current hash of the file containing the translation
    py::class_<td_api::inputPassportElementErrorSourceTranslationFile>(m, "inputPassportElementErrorSourceTranslationFile")
            .def(py::init<>())
    
            .def_readwrite("file_hash", &td_api::inputPassportElementErrorSourceTranslationFile::file_hash_);
    
    // The translation of the document contains an error. The error is considered resolved when the list of files changes @file_hashes Current hashes of all files with the translation
    py::class_<td_api::inputPassportElementErrorSourceTranslationFiles>(m, "inputPassportElementErrorSourceTranslationFiles")
            .def(py::init<>())
    
            .def_readwrite("file_hashes", &td_api::inputPassportElementErrorSourceTranslationFiles::file_hashes_);
    
    // The file contains an error. The error is considered resolved when the file changes @file_hash Current hash of the file which has the error
    py::class_<td_api::inputPassportElementErrorSourceFile>(m, "inputPassportElementErrorSourceFile")
            .def(py::init<>())
    
            .def_readwrite("file_hash", &td_api::inputPassportElementErrorSourceFile::file_hash_);
    
    // The list of attached files contains an error. The error is considered resolved when the file list changes @file_hashes Current hashes of all attached files
    py::class_<td_api::inputPassportElementErrorSourceFiles>(m, "inputPassportElementErrorSourceFiles")
            .def(py::init<>())
    
            .def_readwrite("file_hashes", &td_api::inputPassportElementErrorSourceFiles::file_hashes_);
    
    // Contains the description of an error in a Telegram Passport element; for bots only @type Type of Telegram Passport element that has the error @message Error message @source Error source
    py::class_<td_api::inputPassportElementError>(m, "inputPassportElementError")
            .def(py::init<>())
    
            .def_readwrite("type", &td_api::inputPassportElementError::type_)
            .def_readwrite("message", &td_api::inputPassportElementError::message_)
            .def_readwrite("source", &td_api::inputPassportElementError::source_);
    
    // A text message @text Text of the message @web_page A preview of the web page that's mentioned in the text; may be null
    py::class_<td_api::messageText>(m, "messageText")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::messageText::text_)
            .def_readwrite("web_page", &td_api::messageText::web_page_);
    
    // An animation message (GIF-style). @animation The animation description @caption Animation caption @is_secret True, if the animation thumbnail must be blurred and the animation must be shown only while tapped
    py::class_<td_api::messageAnimation>(m, "messageAnimation")
            .def(py::init<>())
    
            .def_readwrite("animation", &td_api::messageAnimation::animation_)
            .def_readwrite("caption", &td_api::messageAnimation::caption_)
            .def_readwrite("is_secret", &td_api::messageAnimation::is_secret_);
    
    // An audio message @audio The audio description @caption Audio caption
    py::class_<td_api::messageAudio>(m, "messageAudio")
            .def(py::init<>())
    
            .def_readwrite("audio", &td_api::messageAudio::audio_)
            .def_readwrite("caption", &td_api::messageAudio::caption_);
    
    // A document message (general file) @document The document description @caption Document caption
    py::class_<td_api::messageDocument>(m, "messageDocument")
            .def(py::init<>())
    
            .def_readwrite("document", &td_api::messageDocument::document_)
            .def_readwrite("caption", &td_api::messageDocument::caption_);
    
    // A photo message @photo The photo description @caption Photo caption @is_secret True, if the photo must be blurred and must be shown only while tapped
    py::class_<td_api::messagePhoto>(m, "messagePhoto")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::messagePhoto::photo_)
            .def_readwrite("caption", &td_api::messagePhoto::caption_)
            .def_readwrite("is_secret", &td_api::messagePhoto::is_secret_);
    
    // An expired photo message (self-destructed after TTL has elapsed)
    py::class_<td_api::messageExpiredPhoto>(m, "messageExpiredPhoto")
            .def(py::init<>());
    
    // A sticker message @sticker The sticker description
    py::class_<td_api::messageSticker>(m, "messageSticker")
            .def(py::init<>())
    
            .def_readwrite("sticker", &td_api::messageSticker::sticker_);
    
    // A video message @video The video description @caption Video caption @is_secret True, if the video thumbnail must be blurred and the video must be shown only while tapped
    py::class_<td_api::messageVideo>(m, "messageVideo")
            .def(py::init<>())
    
            .def_readwrite("video", &td_api::messageVideo::video_)
            .def_readwrite("caption", &td_api::messageVideo::caption_)
            .def_readwrite("is_secret", &td_api::messageVideo::is_secret_);
    
    // An expired video message (self-destructed after TTL has elapsed)
    py::class_<td_api::messageExpiredVideo>(m, "messageExpiredVideo")
            .def(py::init<>());
    
    // A video note message @video_note The video note description @is_viewed True, if at least one of the recipients has viewed the video note @is_secret True, if the video note thumbnail must be blurred and the video note must be shown only while tapped
    py::class_<td_api::messageVideoNote>(m, "messageVideoNote")
            .def(py::init<>())
    
            .def_readwrite("video_note", &td_api::messageVideoNote::video_note_)
            .def_readwrite("is_viewed", &td_api::messageVideoNote::is_viewed_)
            .def_readwrite("is_secret", &td_api::messageVideoNote::is_secret_);
    
    // A voice note message @voice_note The voice note description @caption Voice note caption @is_listened True, if at least one of the recipients has listened to the voice note
    py::class_<td_api::messageVoiceNote>(m, "messageVoiceNote")
            .def(py::init<>())
    
            .def_readwrite("voice_note", &td_api::messageVoiceNote::voice_note_)
            .def_readwrite("caption", &td_api::messageVoiceNote::caption_)
            .def_readwrite("is_listened", &td_api::messageVoiceNote::is_listened_);
    
    // A message with a location @location The location description @live_period Time relative to the message send date, for which the location can be updated, in seconds
    py::class_<td_api::messageLocation>(m, "messageLocation")
            .def(py::init<>())
    
            .def_readwrite("location", &td_api::messageLocation::location_)
            .def_readwrite("live_period", &td_api::messageLocation::live_period_)
            .def_readwrite("expires_in", &td_api::messageLocation::expires_in_)
            .def_readwrite("heading", &td_api::messageLocation::heading_)
            .def_readwrite("proximity_alert_radius", &td_api::messageLocation::proximity_alert_radius_);
    
    // A message with information about a venue @venue The venue description
    py::class_<td_api::messageVenue>(m, "messageVenue")
            .def(py::init<>())
    
            .def_readwrite("venue", &td_api::messageVenue::venue_);
    
    // A message with a user contact @contact The contact description
    py::class_<td_api::messageContact>(m, "messageContact")
            .def(py::init<>())
    
            .def_readwrite("contact", &td_api::messageContact::contact_);
    
    // A dice message. The dice value is randomly generated by the server
    py::class_<td_api::messageDice>(m, "messageDice")
            .def(py::init<>())
    
            .def_readwrite("initial_state", &td_api::messageDice::initial_state_)
            .def_readwrite("final_state", &td_api::messageDice::final_state_)
            .def_readwrite("emoji", &td_api::messageDice::emoji_)
            .def_readwrite("value", &td_api::messageDice::value_)
            .def_readwrite("success_animation_frame_number", &td_api::messageDice::success_animation_frame_number_);
    
    // A message with a game @game The game description
    py::class_<td_api::messageGame>(m, "messageGame")
            .def(py::init<>())
    
            .def_readwrite("game", &td_api::messageGame::game_);
    
    // A message with a poll @poll The poll description
    py::class_<td_api::messagePoll>(m, "messagePoll")
            .def(py::init<>())
    
            .def_readwrite("poll", &td_api::messagePoll::poll_);
    
    // A message with an invoice from a bot @title Product title @param_description Product description @photo Product photo; may be null @currency Currency for the product price @total_amount Product total price in the smallest units of the currency
    py::class_<td_api::messageInvoice>(m, "messageInvoice")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::messageInvoice::title_)
            .def_readwrite("description", &td_api::messageInvoice::description_)
            .def_readwrite("photo", &td_api::messageInvoice::photo_)
            .def_readwrite("currency", &td_api::messageInvoice::currency_)
            .def_readwrite("total_amount", &td_api::messageInvoice::total_amount_)
            .def_readwrite("start_parameter", &td_api::messageInvoice::start_parameter_)
            .def_readwrite("is_test", &td_api::messageInvoice::is_test_)
            .def_readwrite("need_shipping_address", &td_api::messageInvoice::need_shipping_address_)
            .def_readwrite("receipt_message_id", &td_api::messageInvoice::receipt_message_id_);
    
    // A message with information about an ended call @is_video True, if the call was a video call @discard_reason Reason why the call was discarded @duration Call duration, in seconds
    py::class_<td_api::messageCall>(m, "messageCall")
            .def(py::init<>())
    
            .def_readwrite("is_video", &td_api::messageCall::is_video_)
            .def_readwrite("discard_reason", &td_api::messageCall::discard_reason_)
            .def_readwrite("duration", &td_api::messageCall::duration_);
    
    // A new voice chat was scheduled @group_call_id Identifier of the voice chat. The voice chat can be received through the method getGroupCall @start_date Point in time (Unix timestamp) when the group call is supposed to be started by an administrator
    py::class_<td_api::messageVoiceChatScheduled>(m, "messageVoiceChatScheduled")
            .def(py::init<>())
    
            .def_readwrite("group_call_id", &td_api::messageVoiceChatScheduled::group_call_id_)
            .def_readwrite("start_date", &td_api::messageVoiceChatScheduled::start_date_);
    
    // A newly created voice chat @group_call_id Identifier of the voice chat. The voice chat can be received through the method getGroupCall
    py::class_<td_api::messageVoiceChatStarted>(m, "messageVoiceChatStarted")
            .def(py::init<>())
    
            .def_readwrite("group_call_id", &td_api::messageVoiceChatStarted::group_call_id_);
    
    // A message with information about an ended voice chat @duration Call duration, in seconds
    py::class_<td_api::messageVoiceChatEnded>(m, "messageVoiceChatEnded")
            .def(py::init<>())
    
            .def_readwrite("duration", &td_api::messageVoiceChatEnded::duration_);
    
    // A message with information about an invite to a voice chat @group_call_id Identifier of the voice chat. The voice chat can be received through the method getGroupCall @user_ids Invited user identifiers
    py::class_<td_api::messageInviteVoiceChatParticipants>(m, "messageInviteVoiceChatParticipants")
            .def(py::init<>())
    
            .def_readwrite("group_call_id", &td_api::messageInviteVoiceChatParticipants::group_call_id_)
            .def_readwrite("user_ids", &td_api::messageInviteVoiceChatParticipants::user_ids_);
    
    // A newly created basic group @title Title of the basic group @member_user_ids User identifiers of members in the basic group
    py::class_<td_api::messageBasicGroupChatCreate>(m, "messageBasicGroupChatCreate")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::messageBasicGroupChatCreate::title_)
            .def_readwrite("member_user_ids", &td_api::messageBasicGroupChatCreate::member_user_ids_);
    
    // A newly created supergroup or channel @title Title of the supergroup or channel
    py::class_<td_api::messageSupergroupChatCreate>(m, "messageSupergroupChatCreate")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::messageSupergroupChatCreate::title_);
    
    // An updated chat title @title New chat title
    py::class_<td_api::messageChatChangeTitle>(m, "messageChatChangeTitle")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::messageChatChangeTitle::title_);
    
    // An updated chat photo @photo New chat photo
    py::class_<td_api::messageChatChangePhoto>(m, "messageChatChangePhoto")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::messageChatChangePhoto::photo_);
    
    // A deleted chat photo
    py::class_<td_api::messageChatDeletePhoto>(m, "messageChatDeletePhoto")
            .def(py::init<>());
    
    // New chat members were added @member_user_ids User identifiers of the new members
    py::class_<td_api::messageChatAddMembers>(m, "messageChatAddMembers")
            .def(py::init<>())
    
            .def_readwrite("member_user_ids", &td_api::messageChatAddMembers::member_user_ids_);
    
    // A new member joined the chat by invite link
    py::class_<td_api::messageChatJoinByLink>(m, "messageChatJoinByLink")
            .def(py::init<>());
    
    // A chat member was deleted @user_id User identifier of the deleted chat member
    py::class_<td_api::messageChatDeleteMember>(m, "messageChatDeleteMember")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::messageChatDeleteMember::user_id_);
    
    // A basic group was upgraded to a supergroup and was deactivated as the result @supergroup_id Identifier of the supergroup to which the basic group was upgraded
    py::class_<td_api::messageChatUpgradeTo>(m, "messageChatUpgradeTo")
            .def(py::init<>())
    
            .def_readwrite("supergroup_id", &td_api::messageChatUpgradeTo::supergroup_id_);
    
    // A supergroup has been created from a basic group @title Title of the newly created supergroup @basic_group_id The identifier of the original basic group
    py::class_<td_api::messageChatUpgradeFrom>(m, "messageChatUpgradeFrom")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::messageChatUpgradeFrom::title_)
            .def_readwrite("basic_group_id", &td_api::messageChatUpgradeFrom::basic_group_id_);
    
    // A message has been pinned @message_id Identifier of the pinned message, can be an identifier of a deleted message or 0
    py::class_<td_api::messagePinMessage>(m, "messagePinMessage")
            .def(py::init<>())
    
            .def_readwrite("message_id", &td_api::messagePinMessage::message_id_);
    
    // A screenshot of a message in the chat has been taken
    py::class_<td_api::messageScreenshotTaken>(m, "messageScreenshotTaken")
            .def(py::init<>());
    
    // The TTL (Time To Live) setting for messages in the chat has been changed @ttl New message TTL setting
    py::class_<td_api::messageChatSetTtl>(m, "messageChatSetTtl")
            .def(py::init<>())
    
            .def_readwrite("ttl", &td_api::messageChatSetTtl::ttl_);
    
    // A non-standard action has happened in the chat @text Message text to be shown in the chat
    py::class_<td_api::messageCustomServiceAction>(m, "messageCustomServiceAction")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::messageCustomServiceAction::text_);
    
    // A new high score was achieved in a game @game_message_id Identifier of the message with the game, can be an identifier of a deleted message @game_id Identifier of the game; may be different from the games presented in the message with the game @score New score
    py::class_<td_api::messageGameScore>(m, "messageGameScore")
            .def(py::init<>())
    
            .def_readwrite("game_message_id", &td_api::messageGameScore::game_message_id_)
            .def_readwrite("game_id", &td_api::messageGameScore::game_id_)
            .def_readwrite("score", &td_api::messageGameScore::score_);
    
    // A payment has been completed @invoice_chat_id Identifier of the chat, containing the corresponding invoice message; 0 if unknown @invoice_message_id Identifier of the message with the corresponding invoice; can be an identifier of a deleted message @currency Currency for the price of the product @total_amount Total price for the product, in the smallest units of the currency
    py::class_<td_api::messagePaymentSuccessful>(m, "messagePaymentSuccessful")
            .def(py::init<>())
    
            .def_readwrite("invoice_chat_id", &td_api::messagePaymentSuccessful::invoice_chat_id_)
            .def_readwrite("invoice_message_id", &td_api::messagePaymentSuccessful::invoice_message_id_)
            .def_readwrite("currency", &td_api::messagePaymentSuccessful::currency_)
            .def_readwrite("total_amount", &td_api::messagePaymentSuccessful::total_amount_);
    
    // A payment has been completed; for bots only @currency Currency for price of the product
    py::class_<td_api::messagePaymentSuccessfulBot>(m, "messagePaymentSuccessfulBot")
            .def(py::init<>())
    
            .def_readwrite("currency", &td_api::messagePaymentSuccessfulBot::currency_)
            .def_readwrite("total_amount", &td_api::messagePaymentSuccessfulBot::total_amount_)
            .def_readwrite("invoice_payload", &td_api::messagePaymentSuccessfulBot::invoice_payload_)
            .def_readwrite("shipping_option_id", &td_api::messagePaymentSuccessfulBot::shipping_option_id_)
            .def_readwrite("order_info", &td_api::messagePaymentSuccessfulBot::order_info_)
            .def_readwrite("telegram_payment_charge_id", &td_api::messagePaymentSuccessfulBot::telegram_payment_charge_id_)
            .def_readwrite("provider_payment_charge_id", &td_api::messagePaymentSuccessfulBot::provider_payment_charge_id_);
    
    // A contact has registered with Telegram
    py::class_<td_api::messageContactRegistered>(m, "messageContactRegistered")
            .def(py::init<>());
    
    // The current user has connected a website by logging in using Telegram Login Widget on it @domain_name Domain name of the connected website
    py::class_<td_api::messageWebsiteConnected>(m, "messageWebsiteConnected")
            .def(py::init<>())
    
            .def_readwrite("domain_name", &td_api::messageWebsiteConnected::domain_name_);
    
    // Telegram Passport data has been sent @types List of Telegram Passport element types sent
    py::class_<td_api::messagePassportDataSent>(m, "messagePassportDataSent")
            .def(py::init<>())
    
            .def_readwrite("types", &td_api::messagePassportDataSent::types_);
    
    // Telegram Passport data has been received; for bots only @elements List of received Telegram Passport elements @credentials Encrypted data credentials
    py::class_<td_api::messagePassportDataReceived>(m, "messagePassportDataReceived")
            .def(py::init<>())
    
            .def_readwrite("elements", &td_api::messagePassportDataReceived::elements_)
            .def_readwrite("credentials", &td_api::messagePassportDataReceived::credentials_);
    
    // A user in the chat came within proximity alert range @traveler The user or chat, which triggered the proximity alert @watcher The user or chat, which subscribed for the proximity alert @distance The distance between the users
    py::class_<td_api::messageProximityAlertTriggered>(m, "messageProximityAlertTriggered")
            .def(py::init<>())
    
            .def_readwrite("traveler", &td_api::messageProximityAlertTriggered::traveler_)
            .def_readwrite("watcher", &td_api::messageProximityAlertTriggered::watcher_)
            .def_readwrite("distance", &td_api::messageProximityAlertTriggered::distance_);
    
    // Message content that is not supported in the current TDLib version
    py::class_<td_api::messageUnsupported>(m, "messageUnsupported")
            .def(py::init<>());
    
    // A mention of a user by their username
    py::class_<td_api::textEntityTypeMention>(m, "textEntityTypeMention")
            .def(py::init<>());
    
    // A hashtag text, beginning with "#"
    py::class_<td_api::textEntityTypeHashtag>(m, "textEntityTypeHashtag")
            .def(py::init<>());
    
    // A cashtag text, beginning with "$" and consisting of capital english letters (i.e. "$USD")
    py::class_<td_api::textEntityTypeCashtag>(m, "textEntityTypeCashtag")
            .def(py::init<>());
    
    // A bot command, beginning with "/"
    py::class_<td_api::textEntityTypeBotCommand>(m, "textEntityTypeBotCommand")
            .def(py::init<>());
    
    // An HTTP URL
    py::class_<td_api::textEntityTypeUrl>(m, "textEntityTypeUrl")
            .def(py::init<>());
    
    // An email address
    py::class_<td_api::textEntityTypeEmailAddress>(m, "textEntityTypeEmailAddress")
            .def(py::init<>());
    
    // A phone number
    py::class_<td_api::textEntityTypePhoneNumber>(m, "textEntityTypePhoneNumber")
            .def(py::init<>());
    
    // A bank card number. The getBankCardInfo method can be used to get information about the bank card
    py::class_<td_api::textEntityTypeBankCardNumber>(m, "textEntityTypeBankCardNumber")
            .def(py::init<>());
    
    // A bold text
    py::class_<td_api::textEntityTypeBold>(m, "textEntityTypeBold")
            .def(py::init<>());
    
    // An italic text
    py::class_<td_api::textEntityTypeItalic>(m, "textEntityTypeItalic")
            .def(py::init<>());
    
    // An underlined text
    py::class_<td_api::textEntityTypeUnderline>(m, "textEntityTypeUnderline")
            .def(py::init<>());
    
    // A strikethrough text
    py::class_<td_api::textEntityTypeStrikethrough>(m, "textEntityTypeStrikethrough")
            .def(py::init<>());
    
    // Text that must be formatted as if inside a code HTML tag
    py::class_<td_api::textEntityTypeCode>(m, "textEntityTypeCode")
            .def(py::init<>());
    
    // Text that must be formatted as if inside a pre HTML tag
    py::class_<td_api::textEntityTypePre>(m, "textEntityTypePre")
            .def(py::init<>());
    
    // Text that must be formatted as if inside pre, and code HTML tags @language Programming language of the code; as defined by the sender
    py::class_<td_api::textEntityTypePreCode>(m, "textEntityTypePreCode")
            .def(py::init<>())
    
            .def_readwrite("language", &td_api::textEntityTypePreCode::language_);
    
    // A text description shown instead of a raw URL @url HTTP or tg:// URL to be opened when the link is clicked
    py::class_<td_api::textEntityTypeTextUrl>(m, "textEntityTypeTextUrl")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::textEntityTypeTextUrl::url_);
    
    // A text shows instead of a raw mention of the user (e.g., when the user has no username) @user_id Identifier of the mentioned user
    py::class_<td_api::textEntityTypeMentionName>(m, "textEntityTypeMentionName")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::textEntityTypeMentionName::user_id_);
    
    // A thumbnail to be sent along with a file; must be in JPEG or WEBP format for stickers, and less than 200 KB in size @thumbnail Thumbnail file to send. Sending thumbnails by file_id is currently not supported
    py::class_<td_api::inputThumbnail>(m, "inputThumbnail")
            .def(py::init<>())
    
            .def_readwrite("thumbnail", &td_api::inputThumbnail::thumbnail_)
            .def_readwrite("width", &td_api::inputThumbnail::width_)
            .def_readwrite("height", &td_api::inputThumbnail::height_);
    
    // The message will be sent at the specified date @send_date Date the message will be sent. The date must be within 367 days in the future
    py::class_<td_api::messageSchedulingStateSendAtDate>(m, "messageSchedulingStateSendAtDate")
            .def(py::init<>())
    
            .def_readwrite("send_date", &td_api::messageSchedulingStateSendAtDate::send_date_);
    
    // The message will be sent when the peer will be online. Applicable to private chats only and when the exact online status of the peer is known
    py::class_<td_api::messageSchedulingStateSendWhenOnline>(m, "messageSchedulingStateSendWhenOnline")
            .def(py::init<>());
    
    // Options to be used when a message is sent
    py::class_<td_api::messageSendOptions>(m, "messageSendOptions")
            .def(py::init<>())
    
            .def_readwrite("disable_notification", &td_api::messageSendOptions::disable_notification_)
            .def_readwrite("from_background", &td_api::messageSendOptions::from_background_)
            .def_readwrite("scheduling_state", &td_api::messageSendOptions::scheduling_state_);
    
    // Options to be used when a message content is copied without a link to the original message. Service messages and messageInvoice can't be copied
    py::class_<td_api::messageCopyOptions>(m, "messageCopyOptions")
            .def(py::init<>())
    
            .def_readwrite("send_copy", &td_api::messageCopyOptions::send_copy_)
            .def_readwrite("replace_caption", &td_api::messageCopyOptions::replace_caption_)
            .def_readwrite("new_caption", &td_api::messageCopyOptions::new_caption_);
    
    // A text message @text Formatted text to be sent; 1-GetOption("message_text_length_max") characters. Only Bold, Italic, Underline, Strikethrough, Code, Pre, PreCode, TextUrl and MentionName entities are allowed to be specified manually
    py::class_<td_api::inputMessageText>(m, "inputMessageText")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::inputMessageText::text_)
            .def_readwrite("disable_web_page_preview", &td_api::inputMessageText::disable_web_page_preview_)
            .def_readwrite("clear_draft", &td_api::inputMessageText::clear_draft_);
    
    // An animation message (GIF-style). @animation Animation file to be sent @thumbnail Animation thumbnail, if available @added_sticker_file_ids File identifiers of the stickers added to the animation, if applicable
    py::class_<td_api::inputMessageAnimation>(m, "inputMessageAnimation")
            .def(py::init<>())
    
            .def_readwrite("animation", &td_api::inputMessageAnimation::animation_)
            .def_readwrite("thumbnail", &td_api::inputMessageAnimation::thumbnail_)
            .def_readwrite("added_sticker_file_ids", &td_api::inputMessageAnimation::added_sticker_file_ids_)
            .def_readwrite("duration", &td_api::inputMessageAnimation::duration_)
            .def_readwrite("width", &td_api::inputMessageAnimation::width_)
            .def_readwrite("height", &td_api::inputMessageAnimation::height_)
            .def_readwrite("caption", &td_api::inputMessageAnimation::caption_);
    
    // An audio message @audio Audio file to be sent @album_cover_thumbnail Thumbnail of the cover for the album, if available @duration Duration of the audio, in seconds; may be replaced by the server @title Title of the audio; 0-64 characters; may be replaced by the server
    py::class_<td_api::inputMessageAudio>(m, "inputMessageAudio")
            .def(py::init<>())
    
            .def_readwrite("audio", &td_api::inputMessageAudio::audio_)
            .def_readwrite("album_cover_thumbnail", &td_api::inputMessageAudio::album_cover_thumbnail_)
            .def_readwrite("duration", &td_api::inputMessageAudio::duration_)
            .def_readwrite("title", &td_api::inputMessageAudio::title_)
            .def_readwrite("performer", &td_api::inputMessageAudio::performer_)
            .def_readwrite("caption", &td_api::inputMessageAudio::caption_);
    
    // A document message (general file) @document Document to be sent @thumbnail Document thumbnail, if available @disable_content_type_detection If true, automatic file type detection will be disabled and the document will be always sent as file. Always true for files sent to secret chats @caption Document caption; 0-GetOption("message_caption_length_max") characters
    py::class_<td_api::inputMessageDocument>(m, "inputMessageDocument")
            .def(py::init<>())
    
            .def_readwrite("document", &td_api::inputMessageDocument::document_)
            .def_readwrite("thumbnail", &td_api::inputMessageDocument::thumbnail_)
            .def_readwrite("disable_content_type_detection", &td_api::inputMessageDocument::disable_content_type_detection_)
            .def_readwrite("caption", &td_api::inputMessageDocument::caption_);
    
    // A photo message @photo Photo to send @thumbnail Photo thumbnail to be sent, this is sent to the other party in secret chats only @added_sticker_file_ids File identifiers of the stickers added to the photo, if applicable @width Photo width @height Photo height @caption Photo caption; 0-GetOption("message_caption_length_max") characters
    py::class_<td_api::inputMessagePhoto>(m, "inputMessagePhoto")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::inputMessagePhoto::photo_)
            .def_readwrite("thumbnail", &td_api::inputMessagePhoto::thumbnail_)
            .def_readwrite("added_sticker_file_ids", &td_api::inputMessagePhoto::added_sticker_file_ids_)
            .def_readwrite("width", &td_api::inputMessagePhoto::width_)
            .def_readwrite("height", &td_api::inputMessagePhoto::height_)
            .def_readwrite("caption", &td_api::inputMessagePhoto::caption_)
            .def_readwrite("ttl", &td_api::inputMessagePhoto::ttl_);
    
    // A sticker message @sticker Sticker to be sent @thumbnail Sticker thumbnail, if available @width Sticker width @height Sticker height @emoji Emoji used to choose the sticker
    py::class_<td_api::inputMessageSticker>(m, "inputMessageSticker")
            .def(py::init<>())
    
            .def_readwrite("sticker", &td_api::inputMessageSticker::sticker_)
            .def_readwrite("thumbnail", &td_api::inputMessageSticker::thumbnail_)
            .def_readwrite("width", &td_api::inputMessageSticker::width_)
            .def_readwrite("height", &td_api::inputMessageSticker::height_)
            .def_readwrite("emoji", &td_api::inputMessageSticker::emoji_);
    
    // A video message @video Video to be sent @thumbnail Video thumbnail, if available @added_sticker_file_ids File identifiers of the stickers added to the video, if applicable
    py::class_<td_api::inputMessageVideo>(m, "inputMessageVideo")
            .def(py::init<>())
    
            .def_readwrite("video", &td_api::inputMessageVideo::video_)
            .def_readwrite("thumbnail", &td_api::inputMessageVideo::thumbnail_)
            .def_readwrite("added_sticker_file_ids", &td_api::inputMessageVideo::added_sticker_file_ids_)
            .def_readwrite("duration", &td_api::inputMessageVideo::duration_)
            .def_readwrite("width", &td_api::inputMessageVideo::width_)
            .def_readwrite("height", &td_api::inputMessageVideo::height_)
            .def_readwrite("supports_streaming", &td_api::inputMessageVideo::supports_streaming_)
            .def_readwrite("caption", &td_api::inputMessageVideo::caption_)
            .def_readwrite("ttl", &td_api::inputMessageVideo::ttl_);
    
    // A video note message @video_note Video note to be sent @thumbnail Video thumbnail, if available @duration Duration of the video, in seconds @length Video width and height; must be positive and not greater than 640
    py::class_<td_api::inputMessageVideoNote>(m, "inputMessageVideoNote")
            .def(py::init<>())
    
            .def_readwrite("video_note", &td_api::inputMessageVideoNote::video_note_)
            .def_readwrite("thumbnail", &td_api::inputMessageVideoNote::thumbnail_)
            .def_readwrite("duration", &td_api::inputMessageVideoNote::duration_)
            .def_readwrite("length", &td_api::inputMessageVideoNote::length_);
    
    // A voice note message @voice_note Voice note to be sent @duration Duration of the voice note, in seconds @waveform Waveform representation of the voice note, in 5-bit format @caption Voice note caption; 0-GetOption("message_caption_length_max") characters
    py::class_<td_api::inputMessageVoiceNote>(m, "inputMessageVoiceNote")
            .def(py::init<>())
    
            .def_readwrite("voice_note", &td_api::inputMessageVoiceNote::voice_note_)
            .def_readwrite("duration", &td_api::inputMessageVoiceNote::duration_)
            .def_readwrite("waveform", &td_api::inputMessageVoiceNote::waveform_)
            .def_readwrite("caption", &td_api::inputMessageVoiceNote::caption_);
    
    // A message with a location @location Location to be sent @live_period Period for which the location can be updated, in seconds; should be between 60 and 86400 for a live location and 0 otherwise
    py::class_<td_api::inputMessageLocation>(m, "inputMessageLocation")
            .def(py::init<>())
    
            .def_readwrite("location", &td_api::inputMessageLocation::location_)
            .def_readwrite("live_period", &td_api::inputMessageLocation::live_period_)
            .def_readwrite("heading", &td_api::inputMessageLocation::heading_)
            .def_readwrite("proximity_alert_radius", &td_api::inputMessageLocation::proximity_alert_radius_);
    
    // A message with information about a venue @venue Venue to send
    py::class_<td_api::inputMessageVenue>(m, "inputMessageVenue")
            .def(py::init<>())
    
            .def_readwrite("venue", &td_api::inputMessageVenue::venue_);
    
    // A message containing a user contact @contact Contact to send
    py::class_<td_api::inputMessageContact>(m, "inputMessageContact")
            .def(py::init<>())
    
            .def_readwrite("contact", &td_api::inputMessageContact::contact_);
    
    // A dice message @emoji Emoji on which the dice throw animation is based @clear_draft True, if a chat message draft should be deleted
    py::class_<td_api::inputMessageDice>(m, "inputMessageDice")
            .def(py::init<>())
    
            .def_readwrite("emoji", &td_api::inputMessageDice::emoji_)
            .def_readwrite("clear_draft", &td_api::inputMessageDice::clear_draft_);
    
    // A message with a game; not supported for channels or secret chats @bot_user_id User identifier of the bot that owns the game @game_short_name Short name of the game
    py::class_<td_api::inputMessageGame>(m, "inputMessageGame")
            .def(py::init<>())
    
            .def_readwrite("bot_user_id", &td_api::inputMessageGame::bot_user_id_)
            .def_readwrite("game_short_name", &td_api::inputMessageGame::game_short_name_);
    
    // A message with an invoice; can be used only by bots @invoice Invoice @title Product title; 1-32 characters @param_description Product description; 0-255 characters
    py::class_<td_api::inputMessageInvoice>(m, "inputMessageInvoice")
            .def(py::init<>())
    
            .def_readwrite("invoice", &td_api::inputMessageInvoice::invoice_)
            .def_readwrite("title", &td_api::inputMessageInvoice::title_)
            .def_readwrite("description", &td_api::inputMessageInvoice::description_)
            .def_readwrite("photo_url", &td_api::inputMessageInvoice::photo_url_)
            .def_readwrite("photo_size", &td_api::inputMessageInvoice::photo_size_)
            .def_readwrite("photo_width", &td_api::inputMessageInvoice::photo_width_)
            .def_readwrite("photo_height", &td_api::inputMessageInvoice::photo_height_)
            .def_readwrite("payload", &td_api::inputMessageInvoice::payload_)
            .def_readwrite("provider_token", &td_api::inputMessageInvoice::provider_token_)
            .def_readwrite("provider_data", &td_api::inputMessageInvoice::provider_data_)
            .def_readwrite("start_parameter", &td_api::inputMessageInvoice::start_parameter_);
    
    // A message with a poll. Polls can't be sent to secret chats. Polls can be sent only to a private chat with a bot @question Poll question; 1-255 characters (up to 300 characters for bots) @options List of poll answer options, 2-10 strings 1-100 characters each
    py::class_<td_api::inputMessagePoll>(m, "inputMessagePoll")
            .def(py::init<>())
    
            .def_readwrite("question", &td_api::inputMessagePoll::question_)
            .def_readwrite("options", &td_api::inputMessagePoll::options_)
            .def_readwrite("is_anonymous", &td_api::inputMessagePoll::is_anonymous_)
            .def_readwrite("type", &td_api::inputMessagePoll::type_)
            .def_readwrite("open_period", &td_api::inputMessagePoll::open_period_)
            .def_readwrite("close_date", &td_api::inputMessagePoll::close_date_)
            .def_readwrite("is_closed", &td_api::inputMessagePoll::is_closed_);
    
    // A forwarded message @from_chat_id Identifier for the chat this forwarded message came from @message_id Identifier of the message to forward
    py::class_<td_api::inputMessageForwarded>(m, "inputMessageForwarded")
            .def(py::init<>())
    
            .def_readwrite("from_chat_id", &td_api::inputMessageForwarded::from_chat_id_)
            .def_readwrite("message_id", &td_api::inputMessageForwarded::message_id_)
            .def_readwrite("in_game_share", &td_api::inputMessageForwarded::in_game_share_)
            .def_readwrite("copy_options", &td_api::inputMessageForwarded::copy_options_);
    
    // Returns all found messages, no filter is applied
    py::class_<td_api::searchMessagesFilterEmpty>(m, "searchMessagesFilterEmpty")
            .def(py::init<>());
    
    // Returns only animation messages
    py::class_<td_api::searchMessagesFilterAnimation>(m, "searchMessagesFilterAnimation")
            .def(py::init<>());
    
    // Returns only audio messages
    py::class_<td_api::searchMessagesFilterAudio>(m, "searchMessagesFilterAudio")
            .def(py::init<>());
    
    // Returns only document messages
    py::class_<td_api::searchMessagesFilterDocument>(m, "searchMessagesFilterDocument")
            .def(py::init<>());
    
    // Returns only photo messages
    py::class_<td_api::searchMessagesFilterPhoto>(m, "searchMessagesFilterPhoto")
            .def(py::init<>());
    
    // Returns only video messages
    py::class_<td_api::searchMessagesFilterVideo>(m, "searchMessagesFilterVideo")
            .def(py::init<>());
    
    // Returns only voice note messages
    py::class_<td_api::searchMessagesFilterVoiceNote>(m, "searchMessagesFilterVoiceNote")
            .def(py::init<>());
    
    // Returns only photo and video messages
    py::class_<td_api::searchMessagesFilterPhotoAndVideo>(m, "searchMessagesFilterPhotoAndVideo")
            .def(py::init<>());
    
    // Returns only messages containing URLs
    py::class_<td_api::searchMessagesFilterUrl>(m, "searchMessagesFilterUrl")
            .def(py::init<>());
    
    // Returns only messages containing chat photos
    py::class_<td_api::searchMessagesFilterChatPhoto>(m, "searchMessagesFilterChatPhoto")
            .def(py::init<>());
    
    // Returns only call messages
    py::class_<td_api::searchMessagesFilterCall>(m, "searchMessagesFilterCall")
            .def(py::init<>());
    
    // Returns only incoming call messages with missed/declined discard reasons
    py::class_<td_api::searchMessagesFilterMissedCall>(m, "searchMessagesFilterMissedCall")
            .def(py::init<>());
    
    // Returns only video note messages
    py::class_<td_api::searchMessagesFilterVideoNote>(m, "searchMessagesFilterVideoNote")
            .def(py::init<>());
    
    // Returns only voice and video note messages
    py::class_<td_api::searchMessagesFilterVoiceAndVideoNote>(m, "searchMessagesFilterVoiceAndVideoNote")
            .def(py::init<>());
    
    // Returns only messages with mentions of the current user, or messages that are replies to their messages
    py::class_<td_api::searchMessagesFilterMention>(m, "searchMessagesFilterMention")
            .def(py::init<>());
    
    // Returns only messages with unread mentions of the current user, or messages that are replies to their messages. When using this filter the results can't be additionally filtered by a query, a message thread or by the sending user
    py::class_<td_api::searchMessagesFilterUnreadMention>(m, "searchMessagesFilterUnreadMention")
            .def(py::init<>());
    
    // Returns only failed to send messages. This filter can be used only if the message database is used
    py::class_<td_api::searchMessagesFilterFailedToSend>(m, "searchMessagesFilterFailedToSend")
            .def(py::init<>());
    
    // Returns only pinned messages
    py::class_<td_api::searchMessagesFilterPinned>(m, "searchMessagesFilterPinned")
            .def(py::init<>());
    
    // The user is typing a message
    py::class_<td_api::chatActionTyping>(m, "chatActionTyping")
            .def(py::init<>());
    
    // The user is recording a video
    py::class_<td_api::chatActionRecordingVideo>(m, "chatActionRecordingVideo")
            .def(py::init<>());
    
    // The user is uploading a video @progress Upload progress, as a percentage
    py::class_<td_api::chatActionUploadingVideo>(m, "chatActionUploadingVideo")
            .def(py::init<>())
    
            .def_readwrite("progress", &td_api::chatActionUploadingVideo::progress_);
    
    // The user is recording a voice note
    py::class_<td_api::chatActionRecordingVoiceNote>(m, "chatActionRecordingVoiceNote")
            .def(py::init<>());
    
    // The user is uploading a voice note @progress Upload progress, as a percentage
    py::class_<td_api::chatActionUploadingVoiceNote>(m, "chatActionUploadingVoiceNote")
            .def(py::init<>())
    
            .def_readwrite("progress", &td_api::chatActionUploadingVoiceNote::progress_);
    
    // The user is uploading a photo @progress Upload progress, as a percentage
    py::class_<td_api::chatActionUploadingPhoto>(m, "chatActionUploadingPhoto")
            .def(py::init<>())
    
            .def_readwrite("progress", &td_api::chatActionUploadingPhoto::progress_);
    
    // The user is uploading a document @progress Upload progress, as a percentage
    py::class_<td_api::chatActionUploadingDocument>(m, "chatActionUploadingDocument")
            .def(py::init<>())
    
            .def_readwrite("progress", &td_api::chatActionUploadingDocument::progress_);
    
    // The user is picking a location or venue to send
    py::class_<td_api::chatActionChoosingLocation>(m, "chatActionChoosingLocation")
            .def(py::init<>());
    
    // The user is picking a contact to send
    py::class_<td_api::chatActionChoosingContact>(m, "chatActionChoosingContact")
            .def(py::init<>());
    
    // The user has started to play a game
    py::class_<td_api::chatActionStartPlayingGame>(m, "chatActionStartPlayingGame")
            .def(py::init<>());
    
    // The user is recording a video note
    py::class_<td_api::chatActionRecordingVideoNote>(m, "chatActionRecordingVideoNote")
            .def(py::init<>());
    
    // The user is uploading a video note @progress Upload progress, as a percentage
    py::class_<td_api::chatActionUploadingVideoNote>(m, "chatActionUploadingVideoNote")
            .def(py::init<>())
    
            .def_readwrite("progress", &td_api::chatActionUploadingVideoNote::progress_);
    
    // The user has canceled the previous action
    py::class_<td_api::chatActionCancel>(m, "chatActionCancel")
            .def(py::init<>());
    
    // The user status was never changed
    py::class_<td_api::userStatusEmpty>(m, "userStatusEmpty")
            .def(py::init<>());
    
    // The user is online @expires Point in time (Unix timestamp) when the user's online status will expire
    py::class_<td_api::userStatusOnline>(m, "userStatusOnline")
            .def(py::init<>())
    
            .def_readwrite("expires", &td_api::userStatusOnline::expires_);
    
    // The user is offline @was_online Point in time (Unix timestamp) when the user was last online
    py::class_<td_api::userStatusOffline>(m, "userStatusOffline")
            .def(py::init<>())
    
            .def_readwrite("was_online", &td_api::userStatusOffline::was_online_);
    
    // The user was online recently
    py::class_<td_api::userStatusRecently>(m, "userStatusRecently")
            .def(py::init<>());
    
    // The user is offline, but was online last week
    py::class_<td_api::userStatusLastWeek>(m, "userStatusLastWeek")
            .def(py::init<>());
    
    // The user is offline, but was online last month
    py::class_<td_api::userStatusLastMonth>(m, "userStatusLastMonth")
            .def(py::init<>());
    
    // Represents a list of stickers @stickers List of stickers
    py::class_<td_api::stickers>(m, "stickers")
            .def(py::init<>())
    
            .def_readwrite("stickers", &td_api::stickers::stickers_);
    
    // Represents a list of emoji @emojis List of emojis
    py::class_<td_api::emojis>(m, "emojis")
            .def(py::init<>())
    
            .def_readwrite("emojis", &td_api::emojis::emojis_);
    
    // Represents a sticker set
    py::class_<td_api::stickerSet>(m, "stickerSet")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::stickerSet::id_)
            .def_readwrite("title", &td_api::stickerSet::title_)
            .def_readwrite("name", &td_api::stickerSet::name_)
            .def_readwrite("thumbnail", &td_api::stickerSet::thumbnail_)
            .def_readwrite("thumbnail_outline", &td_api::stickerSet::thumbnail_outline_)
            .def_readwrite("is_installed", &td_api::stickerSet::is_installed_)
            .def_readwrite("is_archived", &td_api::stickerSet::is_archived_)
            .def_readwrite("is_official", &td_api::stickerSet::is_official_)
            .def_readwrite("is_animated", &td_api::stickerSet::is_animated_)
            .def_readwrite("is_masks", &td_api::stickerSet::is_masks_)
            .def_readwrite("is_viewed", &td_api::stickerSet::is_viewed_)
            .def_readwrite("stickers", &td_api::stickerSet::stickers_)
            .def_readwrite("emojis", &td_api::stickerSet::emojis_);
    
    // Represents short information about a sticker set
    py::class_<td_api::stickerSetInfo>(m, "stickerSetInfo")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::stickerSetInfo::id_)
            .def_readwrite("title", &td_api::stickerSetInfo::title_)
            .def_readwrite("name", &td_api::stickerSetInfo::name_)
            .def_readwrite("thumbnail", &td_api::stickerSetInfo::thumbnail_)
            .def_readwrite("thumbnail_outline", &td_api::stickerSetInfo::thumbnail_outline_)
            .def_readwrite("is_installed", &td_api::stickerSetInfo::is_installed_)
            .def_readwrite("is_archived", &td_api::stickerSetInfo::is_archived_)
            .def_readwrite("is_official", &td_api::stickerSetInfo::is_official_)
            .def_readwrite("is_animated", &td_api::stickerSetInfo::is_animated_)
            .def_readwrite("is_masks", &td_api::stickerSetInfo::is_masks_)
            .def_readwrite("is_viewed", &td_api::stickerSetInfo::is_viewed_)
            .def_readwrite("size", &td_api::stickerSetInfo::size_)
            .def_readwrite("covers", &td_api::stickerSetInfo::covers_);
    
    // Represents a list of sticker sets @total_count Approximate total number of sticker sets found @sets List of sticker sets
    py::class_<td_api::stickerSets>(m, "stickerSets")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::stickerSets::total_count_)
            .def_readwrite("sets", &td_api::stickerSets::sets_);
    
    // The call wasn't discarded, or the reason is unknown
    py::class_<td_api::callDiscardReasonEmpty>(m, "callDiscardReasonEmpty")
            .def(py::init<>());
    
    // The call was ended before the conversation started. It was canceled by the caller or missed by the other party
    py::class_<td_api::callDiscardReasonMissed>(m, "callDiscardReasonMissed")
            .def(py::init<>());
    
    // The call was ended before the conversation started. It was declined by the other party
    py::class_<td_api::callDiscardReasonDeclined>(m, "callDiscardReasonDeclined")
            .def(py::init<>());
    
    // The call was ended during the conversation because the users were disconnected
    py::class_<td_api::callDiscardReasonDisconnected>(m, "callDiscardReasonDisconnected")
            .def(py::init<>());
    
    // The call was ended because one of the parties hung up
    py::class_<td_api::callDiscardReasonHungUp>(m, "callDiscardReasonHungUp")
            .def(py::init<>());
    
    // Specifies the supported call protocols
    py::class_<td_api::callProtocol>(m, "callProtocol")
            .def(py::init<>())
    
            .def_readwrite("udp_p2p", &td_api::callProtocol::udp_p2p_)
            .def_readwrite("udp_reflector", &td_api::callProtocol::udp_reflector_)
            .def_readwrite("min_layer", &td_api::callProtocol::min_layer_)
            .def_readwrite("max_layer", &td_api::callProtocol::max_layer_)
            .def_readwrite("library_versions", &td_api::callProtocol::library_versions_);
    
    // A Telegram call reflector @peer_tag A peer tag to be used with the reflector
    py::class_<td_api::callServerTypeTelegramReflector>(m, "callServerTypeTelegramReflector")
            .def(py::init<>())
    
            .def_readwrite("peer_tag", &td_api::callServerTypeTelegramReflector::peer_tag_);
    
    // A WebRTC server @username Username to be used for authentication @password Authentication password @supports_turn True, if the server supports TURN @supports_stun True, if the server supports STUN
    py::class_<td_api::callServerTypeWebrtc>(m, "callServerTypeWebrtc")
            .def(py::init<>())
    
            .def_readwrite("username", &td_api::callServerTypeWebrtc::username_)
            .def_readwrite("password", &td_api::callServerTypeWebrtc::password_)
            .def_readwrite("supports_turn", &td_api::callServerTypeWebrtc::supports_turn_)
            .def_readwrite("supports_stun", &td_api::callServerTypeWebrtc::supports_stun_);
    
    // Describes a server for relaying call data @id Server identifier @ip_address Server IPv4 address @ipv6_address Server IPv6 address @port Server port number @type Server type
    py::class_<td_api::callServer>(m, "callServer")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::callServer::id_)
            .def_readwrite("ip_address", &td_api::callServer::ip_address_)
            .def_readwrite("ipv6_address", &td_api::callServer::ipv6_address_)
            .def_readwrite("port", &td_api::callServer::port_)
            .def_readwrite("type", &td_api::callServer::type_);
    
    // Contains the call identifier @id Call identifier
    py::class_<td_api::callId>(m, "callId")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::callId::id_);
    
    // Contains the group call identifier @id Group call identifier
    py::class_<td_api::groupCallId>(m, "groupCallId")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::groupCallId::id_);
    
    // The call is pending, waiting to be accepted by a user @is_created True, if the call has already been created by the server @is_received True, if the call has already been received by the other party
    py::class_<td_api::callStatePending>(m, "callStatePending")
            .def(py::init<>())
    
            .def_readwrite("is_created", &td_api::callStatePending::is_created_)
            .def_readwrite("is_received", &td_api::callStatePending::is_received_);
    
    // The call has been answered and encryption keys are being exchanged
    py::class_<td_api::callStateExchangingKeys>(m, "callStateExchangingKeys")
            .def(py::init<>());
    
    // The call is ready to use @protocol Call protocols supported by the peer @servers List of available call servers @config A JSON-encoded call config @encryption_key Call encryption key @emojis Encryption key emojis fingerprint @allow_p2p True, if peer-to-peer connection is allowed by users privacy settings
    py::class_<td_api::callStateReady>(m, "callStateReady")
            .def(py::init<>())
    
            .def_readwrite("protocol", &td_api::callStateReady::protocol_)
            .def_readwrite("servers", &td_api::callStateReady::servers_)
            .def_readwrite("config", &td_api::callStateReady::config_)
            .def_readwrite("encryption_key", &td_api::callStateReady::encryption_key_)
            .def_readwrite("emojis", &td_api::callStateReady::emojis_)
            .def_readwrite("allow_p2p", &td_api::callStateReady::allow_p2p_);
    
    // The call is hanging up after discardCall has been called
    py::class_<td_api::callStateHangingUp>(m, "callStateHangingUp")
            .def(py::init<>());
    
    // The call has ended successfully @reason The reason, why the call has ended @need_rating True, if the call rating should be sent to the server @need_debug_information True, if the call debug information should be sent to the server
    py::class_<td_api::callStateDiscarded>(m, "callStateDiscarded")
            .def(py::init<>())
    
            .def_readwrite("reason", &td_api::callStateDiscarded::reason_)
            .def_readwrite("need_rating", &td_api::callStateDiscarded::need_rating_)
            .def_readwrite("need_debug_information", &td_api::callStateDiscarded::need_debug_information_);
    
    // The call has ended with an error @error Error. An error with the code 4005000 will be returned if an outgoing call is missed because of an expired timeout
    py::class_<td_api::callStateError>(m, "callStateError")
            .def(py::init<>())
    
            .def_readwrite("error", &td_api::callStateError::error_);
    
    // Describes a recently speaking participant in a group call @participant_id Group call participant identifier @is_speaking True, is the user has spoken recently
    py::class_<td_api::groupCallRecentSpeaker>(m, "groupCallRecentSpeaker")
            .def(py::init<>())
    
            .def_readwrite("participant_id", &td_api::groupCallRecentSpeaker::participant_id_)
            .def_readwrite("is_speaking", &td_api::groupCallRecentSpeaker::is_speaking_);
    
    // Describes a group call
    py::class_<td_api::groupCall>(m, "groupCall")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::groupCall::id_)
            .def_readwrite("title", &td_api::groupCall::title_)
            .def_readwrite("scheduled_start_date", &td_api::groupCall::scheduled_start_date_)
            .def_readwrite("enabled_start_notification", &td_api::groupCall::enabled_start_notification_)
            .def_readwrite("is_active", &td_api::groupCall::is_active_)
            .def_readwrite("is_joined", &td_api::groupCall::is_joined_)
            .def_readwrite("need_rejoin", &td_api::groupCall::need_rejoin_)
            .def_readwrite("can_be_managed", &td_api::groupCall::can_be_managed_)
            .def_readwrite("participant_count", &td_api::groupCall::participant_count_)
            .def_readwrite("loaded_all_participants", &td_api::groupCall::loaded_all_participants_)
            .def_readwrite("recent_speakers", &td_api::groupCall::recent_speakers_)
            .def_readwrite("is_my_video_enabled", &td_api::groupCall::is_my_video_enabled_)
            .def_readwrite("is_my_video_paused", &td_api::groupCall::is_my_video_paused_)
            .def_readwrite("can_enable_video", &td_api::groupCall::can_enable_video_)
            .def_readwrite("mute_new_participants", &td_api::groupCall::mute_new_participants_)
            .def_readwrite("can_change_mute_new_participants", &td_api::groupCall::can_change_mute_new_participants_)
            .def_readwrite("record_duration", &td_api::groupCall::record_duration_)
            .def_readwrite("duration", &td_api::groupCall::duration_);
    
    // Describes a group of video synchronization source identifiers @semantics The semantics of sources, one of "SIM" or "FID" @source_ids The list of synchronization source identifiers
    py::class_<td_api::groupCallVideoSourceGroup>(m, "groupCallVideoSourceGroup")
            .def(py::init<>())
    
            .def_readwrite("semantics", &td_api::groupCallVideoSourceGroup::semantics_)
            .def_readwrite("source_ids", &td_api::groupCallVideoSourceGroup::source_ids_);
    
    // Contains information about a group call participant's video channel @source_groups List of synchronization source groups of the video @endpoint_id Video channel endpoint identifier
    py::class_<td_api::groupCallParticipantVideoInfo>(m, "groupCallParticipantVideoInfo")
            .def(py::init<>())
    
            .def_readwrite("source_groups", &td_api::groupCallParticipantVideoInfo::source_groups_)
            .def_readwrite("endpoint_id", &td_api::groupCallParticipantVideoInfo::endpoint_id_)
            .def_readwrite("is_paused", &td_api::groupCallParticipantVideoInfo::is_paused_);
    
    // Represents a group call participant
    py::class_<td_api::groupCallParticipant>(m, "groupCallParticipant")
            .def(py::init<>())
    
            .def_readwrite("participant_id", &td_api::groupCallParticipant::participant_id_)
            .def_readwrite("audio_source_id", &td_api::groupCallParticipant::audio_source_id_)
            .def_readwrite("screen_sharing_audio_source_id", &td_api::groupCallParticipant::screen_sharing_audio_source_id_)
            .def_readwrite("video_info", &td_api::groupCallParticipant::video_info_)
            .def_readwrite("screen_sharing_video_info", &td_api::groupCallParticipant::screen_sharing_video_info_)
            .def_readwrite("bio", &td_api::groupCallParticipant::bio_)
            .def_readwrite("is_current_user", &td_api::groupCallParticipant::is_current_user_)
            .def_readwrite("is_speaking", &td_api::groupCallParticipant::is_speaking_)
            .def_readwrite("is_hand_raised", &td_api::groupCallParticipant::is_hand_raised_)
            .def_readwrite("can_be_muted_for_all_users", &td_api::groupCallParticipant::can_be_muted_for_all_users_)
            .def_readwrite("can_be_unmuted_for_all_users", &td_api::groupCallParticipant::can_be_unmuted_for_all_users_)
            .def_readwrite("can_be_muted_for_current_user", &td_api::groupCallParticipant::can_be_muted_for_current_user_)
            .def_readwrite("can_be_unmuted_for_current_user", &td_api::groupCallParticipant::can_be_unmuted_for_current_user_)
            .def_readwrite("is_muted_for_all_users", &td_api::groupCallParticipant::is_muted_for_all_users_)
            .def_readwrite("is_muted_for_current_user", &td_api::groupCallParticipant::is_muted_for_current_user_)
            .def_readwrite("can_unmute_self", &td_api::groupCallParticipant::can_unmute_self_)
            .def_readwrite("volume_level", &td_api::groupCallParticipant::volume_level_)
            .def_readwrite("order", &td_api::groupCallParticipant::order_);
    
    // The user heard their own voice
    py::class_<td_api::callProblemEcho>(m, "callProblemEcho")
            .def(py::init<>());
    
    // The user heard background noise
    py::class_<td_api::callProblemNoise>(m, "callProblemNoise")
            .def(py::init<>());
    
    // The other side kept disappearing
    py::class_<td_api::callProblemInterruptions>(m, "callProblemInterruptions")
            .def(py::init<>());
    
    // The speech was distorted
    py::class_<td_api::callProblemDistortedSpeech>(m, "callProblemDistortedSpeech")
            .def(py::init<>());
    
    // The user couldn't hear the other side
    py::class_<td_api::callProblemSilentLocal>(m, "callProblemSilentLocal")
            .def(py::init<>());
    
    // The other side couldn't hear the user
    py::class_<td_api::callProblemSilentRemote>(m, "callProblemSilentRemote")
            .def(py::init<>());
    
    // The call ended unexpectedly
    py::class_<td_api::callProblemDropped>(m, "callProblemDropped")
            .def(py::init<>());
    
    // The video was distorted
    py::class_<td_api::callProblemDistortedVideo>(m, "callProblemDistortedVideo")
            .def(py::init<>());
    
    // The video was pixelated
    py::class_<td_api::callProblemPixelatedVideo>(m, "callProblemPixelatedVideo")
            .def(py::init<>());
    
    // Describes a call @id Call identifier, not persistent @user_id Peer user identifier @is_outgoing True, if the call is outgoing @is_video True, if the call is a video call @state Call state
    py::class_<td_api::call>(m, "call")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::call::id_)
            .def_readwrite("user_id", &td_api::call::user_id_)
            .def_readwrite("is_outgoing", &td_api::call::is_outgoing_)
            .def_readwrite("is_video", &td_api::call::is_video_)
            .def_readwrite("state", &td_api::call::state_);
    
    // Contains settings for the authentication of the user's phone number
    py::class_<td_api::phoneNumberAuthenticationSettings>(m, "phoneNumberAuthenticationSettings")
            .def(py::init<>())
    
            .def_readwrite("allow_flash_call", &td_api::phoneNumberAuthenticationSettings::allow_flash_call_)
            .def_readwrite("is_current_phone_number", &td_api::phoneNumberAuthenticationSettings::is_current_phone_number_)
            .def_readwrite("allow_sms_retriever_api", &td_api::phoneNumberAuthenticationSettings::allow_sms_retriever_api_);
    
    // Represents a list of animations @animations List of animations
    py::class_<td_api::animations>(m, "animations")
            .def(py::init<>())
    
            .def_readwrite("animations", &td_api::animations::animations_);
    
    // A regular animated sticker @sticker The animated sticker with the dice animation
    py::class_<td_api::diceStickersRegular>(m, "diceStickersRegular")
            .def(py::init<>())
    
            .def_readwrite("sticker", &td_api::diceStickersRegular::sticker_);
    
    // Animated stickers to be combined into a slot machine
    py::class_<td_api::diceStickersSlotMachine>(m, "diceStickersSlotMachine")
            .def(py::init<>())
    
            .def_readwrite("background", &td_api::diceStickersSlotMachine::background_)
            .def_readwrite("lever", &td_api::diceStickersSlotMachine::lever_)
            .def_readwrite("left_reel", &td_api::diceStickersSlotMachine::left_reel_)
            .def_readwrite("center_reel", &td_api::diceStickersSlotMachine::center_reel_)
            .def_readwrite("right_reel", &td_api::diceStickersSlotMachine::right_reel_);
    
    // Represents the result of an ImportContacts request @user_ids User identifiers of the imported contacts in the same order as they were specified in the request; 0 if the contact is not yet a registered user
    py::class_<td_api::importedContacts>(m, "importedContacts")
            .def(py::init<>())
    
            .def_readwrite("user_ids", &td_api::importedContacts::user_ids_)
            .def_readwrite("importer_count", &td_api::importedContacts::importer_count_);
    
    // Contains an HTTP URL @url The URL
    py::class_<td_api::httpUrl>(m, "httpUrl")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::httpUrl::url_);
    
    // Represents a link to an animated GIF or an animated (i.e. without sound) H.264/MPEG-4 AVC video
    py::class_<td_api::inputInlineQueryResultAnimation>(m, "inputInlineQueryResultAnimation")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultAnimation::id_)
            .def_readwrite("title", &td_api::inputInlineQueryResultAnimation::title_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultAnimation::thumbnail_url_)
            .def_readwrite("thumbnail_mime_type", &td_api::inputInlineQueryResultAnimation::thumbnail_mime_type_)
            .def_readwrite("video_url", &td_api::inputInlineQueryResultAnimation::video_url_)
            .def_readwrite("video_mime_type", &td_api::inputInlineQueryResultAnimation::video_mime_type_)
            .def_readwrite("video_duration", &td_api::inputInlineQueryResultAnimation::video_duration_)
            .def_readwrite("video_width", &td_api::inputInlineQueryResultAnimation::video_width_)
            .def_readwrite("video_height", &td_api::inputInlineQueryResultAnimation::video_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultAnimation::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultAnimation::input_message_content_);
    
    // Represents a link to an article or web page @id Unique identifier of the query result @url URL of the result, if it exists @hide_url True, if the URL must be not shown @title Title of the result
    py::class_<td_api::inputInlineQueryResultArticle>(m, "inputInlineQueryResultArticle")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultArticle::id_)
            .def_readwrite("url", &td_api::inputInlineQueryResultArticle::url_)
            .def_readwrite("hide_url", &td_api::inputInlineQueryResultArticle::hide_url_)
            .def_readwrite("title", &td_api::inputInlineQueryResultArticle::title_)
            .def_readwrite("description", &td_api::inputInlineQueryResultArticle::description_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultArticle::thumbnail_url_)
            .def_readwrite("thumbnail_width", &td_api::inputInlineQueryResultArticle::thumbnail_width_)
            .def_readwrite("thumbnail_height", &td_api::inputInlineQueryResultArticle::thumbnail_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultArticle::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultArticle::input_message_content_);
    
    // Represents a link to an MP3 audio file @id Unique identifier of the query result @title Title of the audio file @performer Performer of the audio file
    py::class_<td_api::inputInlineQueryResultAudio>(m, "inputInlineQueryResultAudio")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultAudio::id_)
            .def_readwrite("title", &td_api::inputInlineQueryResultAudio::title_)
            .def_readwrite("performer", &td_api::inputInlineQueryResultAudio::performer_)
            .def_readwrite("audio_url", &td_api::inputInlineQueryResultAudio::audio_url_)
            .def_readwrite("audio_duration", &td_api::inputInlineQueryResultAudio::audio_duration_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultAudio::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultAudio::input_message_content_);
    
    // Represents a user contact @id Unique identifier of the query result @contact User contact @thumbnail_url URL of the result thumbnail, if it exists @thumbnail_width Thumbnail width, if known @thumbnail_height Thumbnail height, if known
    py::class_<td_api::inputInlineQueryResultContact>(m, "inputInlineQueryResultContact")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultContact::id_)
            .def_readwrite("contact", &td_api::inputInlineQueryResultContact::contact_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultContact::thumbnail_url_)
            .def_readwrite("thumbnail_width", &td_api::inputInlineQueryResultContact::thumbnail_width_)
            .def_readwrite("thumbnail_height", &td_api::inputInlineQueryResultContact::thumbnail_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultContact::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultContact::input_message_content_);
    
    // Represents a link to a file @id Unique identifier of the query result @title Title of the resulting file @param_description Short description of the result, if known @document_url URL of the file @mime_type MIME type of the file content; only "application/pdf" and "application/zip" are currently allowed
    py::class_<td_api::inputInlineQueryResultDocument>(m, "inputInlineQueryResultDocument")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultDocument::id_)
            .def_readwrite("title", &td_api::inputInlineQueryResultDocument::title_)
            .def_readwrite("description", &td_api::inputInlineQueryResultDocument::description_)
            .def_readwrite("document_url", &td_api::inputInlineQueryResultDocument::document_url_)
            .def_readwrite("mime_type", &td_api::inputInlineQueryResultDocument::mime_type_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultDocument::thumbnail_url_)
            .def_readwrite("thumbnail_width", &td_api::inputInlineQueryResultDocument::thumbnail_width_)
            .def_readwrite("thumbnail_height", &td_api::inputInlineQueryResultDocument::thumbnail_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultDocument::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultDocument::input_message_content_);
    
    // Represents a game @id Unique identifier of the query result @game_short_name Short name of the game @reply_markup Message reply markup. Must be of type replyMarkupInlineKeyboard or null
    py::class_<td_api::inputInlineQueryResultGame>(m, "inputInlineQueryResultGame")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultGame::id_)
            .def_readwrite("game_short_name", &td_api::inputInlineQueryResultGame::game_short_name_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultGame::reply_markup_);
    
    // Represents a point on the map @id Unique identifier of the query result @location Location result
    py::class_<td_api::inputInlineQueryResultLocation>(m, "inputInlineQueryResultLocation")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultLocation::id_)
            .def_readwrite("location", &td_api::inputInlineQueryResultLocation::location_)
            .def_readwrite("live_period", &td_api::inputInlineQueryResultLocation::live_period_)
            .def_readwrite("title", &td_api::inputInlineQueryResultLocation::title_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultLocation::thumbnail_url_)
            .def_readwrite("thumbnail_width", &td_api::inputInlineQueryResultLocation::thumbnail_width_)
            .def_readwrite("thumbnail_height", &td_api::inputInlineQueryResultLocation::thumbnail_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultLocation::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultLocation::input_message_content_);
    
    // Represents link to a JPEG image @id Unique identifier of the query result @title Title of the result, if known @param_description A short description of the result, if known @thumbnail_url URL of the photo thumbnail, if it exists
    py::class_<td_api::inputInlineQueryResultPhoto>(m, "inputInlineQueryResultPhoto")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultPhoto::id_)
            .def_readwrite("title", &td_api::inputInlineQueryResultPhoto::title_)
            .def_readwrite("description", &td_api::inputInlineQueryResultPhoto::description_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultPhoto::thumbnail_url_)
            .def_readwrite("photo_url", &td_api::inputInlineQueryResultPhoto::photo_url_)
            .def_readwrite("photo_width", &td_api::inputInlineQueryResultPhoto::photo_width_)
            .def_readwrite("photo_height", &td_api::inputInlineQueryResultPhoto::photo_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultPhoto::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultPhoto::input_message_content_);
    
    // Represents a link to a WEBP or TGS sticker @id Unique identifier of the query result @thumbnail_url URL of the sticker thumbnail, if it exists
    py::class_<td_api::inputInlineQueryResultSticker>(m, "inputInlineQueryResultSticker")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultSticker::id_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultSticker::thumbnail_url_)
            .def_readwrite("sticker_url", &td_api::inputInlineQueryResultSticker::sticker_url_)
            .def_readwrite("sticker_width", &td_api::inputInlineQueryResultSticker::sticker_width_)
            .def_readwrite("sticker_height", &td_api::inputInlineQueryResultSticker::sticker_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultSticker::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultSticker::input_message_content_);
    
    // Represents information about a venue @id Unique identifier of the query result @venue Venue result @thumbnail_url URL of the result thumbnail, if it exists @thumbnail_width Thumbnail width, if known @thumbnail_height Thumbnail height, if known
    py::class_<td_api::inputInlineQueryResultVenue>(m, "inputInlineQueryResultVenue")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultVenue::id_)
            .def_readwrite("venue", &td_api::inputInlineQueryResultVenue::venue_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultVenue::thumbnail_url_)
            .def_readwrite("thumbnail_width", &td_api::inputInlineQueryResultVenue::thumbnail_width_)
            .def_readwrite("thumbnail_height", &td_api::inputInlineQueryResultVenue::thumbnail_height_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultVenue::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultVenue::input_message_content_);
    
    // Represents a link to a page containing an embedded video player or a video file @id Unique identifier of the query result @title Title of the result @param_description A short description of the result, if known
    py::class_<td_api::inputInlineQueryResultVideo>(m, "inputInlineQueryResultVideo")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultVideo::id_)
            .def_readwrite("title", &td_api::inputInlineQueryResultVideo::title_)
            .def_readwrite("description", &td_api::inputInlineQueryResultVideo::description_)
            .def_readwrite("thumbnail_url", &td_api::inputInlineQueryResultVideo::thumbnail_url_)
            .def_readwrite("video_url", &td_api::inputInlineQueryResultVideo::video_url_)
            .def_readwrite("mime_type", &td_api::inputInlineQueryResultVideo::mime_type_)
            .def_readwrite("video_width", &td_api::inputInlineQueryResultVideo::video_width_)
            .def_readwrite("video_height", &td_api::inputInlineQueryResultVideo::video_height_)
            .def_readwrite("video_duration", &td_api::inputInlineQueryResultVideo::video_duration_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultVideo::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultVideo::input_message_content_);
    
    // Represents a link to an opus-encoded audio file within an OGG container, single channel audio @id Unique identifier of the query result @title Title of the voice note
    py::class_<td_api::inputInlineQueryResultVoiceNote>(m, "inputInlineQueryResultVoiceNote")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inputInlineQueryResultVoiceNote::id_)
            .def_readwrite("title", &td_api::inputInlineQueryResultVoiceNote::title_)
            .def_readwrite("voice_note_url", &td_api::inputInlineQueryResultVoiceNote::voice_note_url_)
            .def_readwrite("voice_note_duration", &td_api::inputInlineQueryResultVoiceNote::voice_note_duration_)
            .def_readwrite("reply_markup", &td_api::inputInlineQueryResultVoiceNote::reply_markup_)
            .def_readwrite("input_message_content", &td_api::inputInlineQueryResultVoiceNote::input_message_content_);
    
    // Represents a link to an article or web page @id Unique identifier of the query result @url URL of the result, if it exists @hide_url True, if the URL must be not shown @title Title of the result
    py::class_<td_api::inlineQueryResultArticle>(m, "inlineQueryResultArticle")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultArticle::id_)
            .def_readwrite("url", &td_api::inlineQueryResultArticle::url_)
            .def_readwrite("hide_url", &td_api::inlineQueryResultArticle::hide_url_)
            .def_readwrite("title", &td_api::inlineQueryResultArticle::title_)
            .def_readwrite("description", &td_api::inlineQueryResultArticle::description_)
            .def_readwrite("thumbnail", &td_api::inlineQueryResultArticle::thumbnail_);
    
    // Represents a user contact @id Unique identifier of the query result @contact A user contact @thumbnail Result thumbnail in JPEG format; may be null
    py::class_<td_api::inlineQueryResultContact>(m, "inlineQueryResultContact")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultContact::id_)
            .def_readwrite("contact", &td_api::inlineQueryResultContact::contact_)
            .def_readwrite("thumbnail", &td_api::inlineQueryResultContact::thumbnail_);
    
    // Represents a point on the map @id Unique identifier of the query result @location Location result @title Title of the result @thumbnail Result thumbnail in JPEG format; may be null
    py::class_<td_api::inlineQueryResultLocation>(m, "inlineQueryResultLocation")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultLocation::id_)
            .def_readwrite("location", &td_api::inlineQueryResultLocation::location_)
            .def_readwrite("title", &td_api::inlineQueryResultLocation::title_)
            .def_readwrite("thumbnail", &td_api::inlineQueryResultLocation::thumbnail_);
    
    // Represents information about a venue @id Unique identifier of the query result @venue Venue result @thumbnail Result thumbnail in JPEG format; may be null
    py::class_<td_api::inlineQueryResultVenue>(m, "inlineQueryResultVenue")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultVenue::id_)
            .def_readwrite("venue", &td_api::inlineQueryResultVenue::venue_)
            .def_readwrite("thumbnail", &td_api::inlineQueryResultVenue::thumbnail_);
    
    // Represents information about a game @id Unique identifier of the query result @game Game result
    py::class_<td_api::inlineQueryResultGame>(m, "inlineQueryResultGame")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultGame::id_)
            .def_readwrite("game", &td_api::inlineQueryResultGame::game_);
    
    // Represents an animation file @id Unique identifier of the query result @animation Animation file @title Animation title
    py::class_<td_api::inlineQueryResultAnimation>(m, "inlineQueryResultAnimation")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultAnimation::id_)
            .def_readwrite("animation", &td_api::inlineQueryResultAnimation::animation_)
            .def_readwrite("title", &td_api::inlineQueryResultAnimation::title_);
    
    // Represents an audio file @id Unique identifier of the query result @audio Audio file
    py::class_<td_api::inlineQueryResultAudio>(m, "inlineQueryResultAudio")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultAudio::id_)
            .def_readwrite("audio", &td_api::inlineQueryResultAudio::audio_);
    
    // Represents a document @id Unique identifier of the query result @document Document @title Document title @param_description Document description
    py::class_<td_api::inlineQueryResultDocument>(m, "inlineQueryResultDocument")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultDocument::id_)
            .def_readwrite("document", &td_api::inlineQueryResultDocument::document_)
            .def_readwrite("title", &td_api::inlineQueryResultDocument::title_)
            .def_readwrite("description", &td_api::inlineQueryResultDocument::description_);
    
    // Represents a photo @id Unique identifier of the query result @photo Photo @title Title of the result, if known @param_description A short description of the result, if known
    py::class_<td_api::inlineQueryResultPhoto>(m, "inlineQueryResultPhoto")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultPhoto::id_)
            .def_readwrite("photo", &td_api::inlineQueryResultPhoto::photo_)
            .def_readwrite("title", &td_api::inlineQueryResultPhoto::title_)
            .def_readwrite("description", &td_api::inlineQueryResultPhoto::description_);
    
    // Represents a sticker @id Unique identifier of the query result @sticker Sticker
    py::class_<td_api::inlineQueryResultSticker>(m, "inlineQueryResultSticker")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultSticker::id_)
            .def_readwrite("sticker", &td_api::inlineQueryResultSticker::sticker_);
    
    // Represents a video @id Unique identifier of the query result @video Video @title Title of the video @param_description Description of the video
    py::class_<td_api::inlineQueryResultVideo>(m, "inlineQueryResultVideo")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultVideo::id_)
            .def_readwrite("video", &td_api::inlineQueryResultVideo::video_)
            .def_readwrite("title", &td_api::inlineQueryResultVideo::title_)
            .def_readwrite("description", &td_api::inlineQueryResultVideo::description_);
    
    // Represents a voice note @id Unique identifier of the query result @voice_note Voice note @title Title of the voice note
    py::class_<td_api::inlineQueryResultVoiceNote>(m, "inlineQueryResultVoiceNote")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::inlineQueryResultVoiceNote::id_)
            .def_readwrite("voice_note", &td_api::inlineQueryResultVoiceNote::voice_note_)
            .def_readwrite("title", &td_api::inlineQueryResultVoiceNote::title_);
    
    // Represents the results of the inline query. Use sendInlineQueryResultMessage to send the result of the query @inline_query_id Unique identifier of the inline query @next_offset The offset for the next request. If empty, there are no more results @results Results of the query
    py::class_<td_api::inlineQueryResults>(m, "inlineQueryResults")
            .def(py::init<>())
    
            .def_readwrite("inline_query_id", &td_api::inlineQueryResults::inline_query_id_)
            .def_readwrite("next_offset", &td_api::inlineQueryResults::next_offset_)
            .def_readwrite("results", &td_api::inlineQueryResults::results_)
            .def_readwrite("switch_pm_text", &td_api::inlineQueryResults::switch_pm_text_)
            .def_readwrite("switch_pm_parameter", &td_api::inlineQueryResults::switch_pm_parameter_);
    
    // The payload for a general callback button @data Data that was attached to the callback button
    py::class_<td_api::callbackQueryPayloadData>(m, "callbackQueryPayloadData")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::callbackQueryPayloadData::data_);
    
    // The payload for a callback button requiring password @password The password for the current user @data Data that was attached to the callback button
    py::class_<td_api::callbackQueryPayloadDataWithPassword>(m, "callbackQueryPayloadDataWithPassword")
            .def(py::init<>())
    
            .def_readwrite("password", &td_api::callbackQueryPayloadDataWithPassword::password_)
            .def_readwrite("data", &td_api::callbackQueryPayloadDataWithPassword::data_);
    
    // The payload for a game callback button @game_short_name A short name of the game that was attached to the callback button
    py::class_<td_api::callbackQueryPayloadGame>(m, "callbackQueryPayloadGame")
            .def(py::init<>())
    
            .def_readwrite("game_short_name", &td_api::callbackQueryPayloadGame::game_short_name_);
    
    // Contains a bot's answer to a callback query @text Text of the answer @show_alert True, if an alert should be shown to the user instead of a toast notification @url URL to be opened
    py::class_<td_api::callbackQueryAnswer>(m, "callbackQueryAnswer")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::callbackQueryAnswer::text_)
            .def_readwrite("show_alert", &td_api::callbackQueryAnswer::show_alert_)
            .def_readwrite("url", &td_api::callbackQueryAnswer::url_);
    
    // Contains the result of a custom request @result A JSON-serialized result
    py::class_<td_api::customRequestResult>(m, "customRequestResult")
            .def(py::init<>())
    
            .def_readwrite("result", &td_api::customRequestResult::result_);
    
    // Contains one row of the game high score table @position Position in the high score table @user_id User identifier @score User score
    py::class_<td_api::gameHighScore>(m, "gameHighScore")
            .def(py::init<>())
    
            .def_readwrite("position", &td_api::gameHighScore::position_)
            .def_readwrite("user_id", &td_api::gameHighScore::user_id_)
            .def_readwrite("score", &td_api::gameHighScore::score_);
    
    // Contains a list of game high scores @scores A list of game high scores
    py::class_<td_api::gameHighScores>(m, "gameHighScores")
            .def(py::init<>())
    
            .def_readwrite("scores", &td_api::gameHighScores::scores_);
    
    // A message was edited @old_message The original message before the edit @new_message The message after it was edited
    py::class_<td_api::chatEventMessageEdited>(m, "chatEventMessageEdited")
            .def(py::init<>())
    
            .def_readwrite("old_message", &td_api::chatEventMessageEdited::old_message_)
            .def_readwrite("new_message", &td_api::chatEventMessageEdited::new_message_);
    
    // A message was deleted @message Deleted message
    py::class_<td_api::chatEventMessageDeleted>(m, "chatEventMessageDeleted")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::chatEventMessageDeleted::message_);
    
    // A poll in a message was stopped @message The message with the poll
    py::class_<td_api::chatEventPollStopped>(m, "chatEventPollStopped")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::chatEventPollStopped::message_);
    
    // A message was pinned @message Pinned message
    py::class_<td_api::chatEventMessagePinned>(m, "chatEventMessagePinned")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::chatEventMessagePinned::message_);
    
    // A message was unpinned @message Unpinned message
    py::class_<td_api::chatEventMessageUnpinned>(m, "chatEventMessageUnpinned")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::chatEventMessageUnpinned::message_);
    
    // A new member joined the chat
    py::class_<td_api::chatEventMemberJoined>(m, "chatEventMemberJoined")
            .def(py::init<>());
    
    // A new member joined the chat by an invite link @invite_link Invite link used to join the chat
    py::class_<td_api::chatEventMemberJoinedByInviteLink>(m, "chatEventMemberJoinedByInviteLink")
            .def(py::init<>())
    
            .def_readwrite("invite_link", &td_api::chatEventMemberJoinedByInviteLink::invite_link_);
    
    // A member left the chat
    py::class_<td_api::chatEventMemberLeft>(m, "chatEventMemberLeft")
            .def(py::init<>());
    
    // A new chat member was invited @user_id New member user identifier @status New member status
    py::class_<td_api::chatEventMemberInvited>(m, "chatEventMemberInvited")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatEventMemberInvited::user_id_)
            .def_readwrite("status", &td_api::chatEventMemberInvited::status_);
    
    // A chat member has gained/lost administrator status, or the list of their administrator privileges has changed @user_id Affected chat member user identifier @old_status Previous status of the chat member @new_status New status of the chat member
    py::class_<td_api::chatEventMemberPromoted>(m, "chatEventMemberPromoted")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatEventMemberPromoted::user_id_)
            .def_readwrite("old_status", &td_api::chatEventMemberPromoted::old_status_)
            .def_readwrite("new_status", &td_api::chatEventMemberPromoted::new_status_);
    
    // A chat member was restricted/unrestricted or banned/unbanned, or the list of their restrictions has changed @member_id Affected chat member identifier @old_status Previous status of the chat member @new_status New status of the chat member
    py::class_<td_api::chatEventMemberRestricted>(m, "chatEventMemberRestricted")
            .def(py::init<>())
    
            .def_readwrite("member_id", &td_api::chatEventMemberRestricted::member_id_)
            .def_readwrite("old_status", &td_api::chatEventMemberRestricted::old_status_)
            .def_readwrite("new_status", &td_api::chatEventMemberRestricted::new_status_);
    
    // The chat title was changed @old_title Previous chat title @new_title New chat title
    py::class_<td_api::chatEventTitleChanged>(m, "chatEventTitleChanged")
            .def(py::init<>())
    
            .def_readwrite("old_title", &td_api::chatEventTitleChanged::old_title_)
            .def_readwrite("new_title", &td_api::chatEventTitleChanged::new_title_);
    
    // The chat permissions was changed @old_permissions Previous chat permissions @new_permissions New chat permissions
    py::class_<td_api::chatEventPermissionsChanged>(m, "chatEventPermissionsChanged")
            .def(py::init<>())
    
            .def_readwrite("old_permissions", &td_api::chatEventPermissionsChanged::old_permissions_)
            .def_readwrite("new_permissions", &td_api::chatEventPermissionsChanged::new_permissions_);
    
    // The chat description was changed @old_description Previous chat description @new_description New chat description
    py::class_<td_api::chatEventDescriptionChanged>(m, "chatEventDescriptionChanged")
            .def(py::init<>())
    
            .def_readwrite("old_description", &td_api::chatEventDescriptionChanged::old_description_)
            .def_readwrite("new_description", &td_api::chatEventDescriptionChanged::new_description_);
    
    // The chat username was changed @old_username Previous chat username @new_username New chat username
    py::class_<td_api::chatEventUsernameChanged>(m, "chatEventUsernameChanged")
            .def(py::init<>())
    
            .def_readwrite("old_username", &td_api::chatEventUsernameChanged::old_username_)
            .def_readwrite("new_username", &td_api::chatEventUsernameChanged::new_username_);
    
    // The chat photo was changed @old_photo Previous chat photo value; may be null @new_photo New chat photo value; may be null
    py::class_<td_api::chatEventPhotoChanged>(m, "chatEventPhotoChanged")
            .def(py::init<>())
    
            .def_readwrite("old_photo", &td_api::chatEventPhotoChanged::old_photo_)
            .def_readwrite("new_photo", &td_api::chatEventPhotoChanged::new_photo_);
    
    // The can_invite_users permission of a supergroup chat was toggled @can_invite_users New value of can_invite_users permission
    py::class_<td_api::chatEventInvitesToggled>(m, "chatEventInvitesToggled")
            .def(py::init<>())
    
            .def_readwrite("can_invite_users", &td_api::chatEventInvitesToggled::can_invite_users_);
    
    // The linked chat of a supergroup was changed @old_linked_chat_id Previous supergroup linked chat identifier @new_linked_chat_id New supergroup linked chat identifier
    py::class_<td_api::chatEventLinkedChatChanged>(m, "chatEventLinkedChatChanged")
            .def(py::init<>())
    
            .def_readwrite("old_linked_chat_id", &td_api::chatEventLinkedChatChanged::old_linked_chat_id_)
            .def_readwrite("new_linked_chat_id", &td_api::chatEventLinkedChatChanged::new_linked_chat_id_);
    
    // The slow_mode_delay setting of a supergroup was changed @old_slow_mode_delay Previous value of slow_mode_delay @new_slow_mode_delay New value of slow_mode_delay
    py::class_<td_api::chatEventSlowModeDelayChanged>(m, "chatEventSlowModeDelayChanged")
            .def(py::init<>())
    
            .def_readwrite("old_slow_mode_delay", &td_api::chatEventSlowModeDelayChanged::old_slow_mode_delay_)
            .def_readwrite("new_slow_mode_delay", &td_api::chatEventSlowModeDelayChanged::new_slow_mode_delay_);
    
    // The message TTL setting was changed @old_message_ttl_setting Previous value of message_ttl_setting @new_message_ttl_setting New value of message_ttl_setting
    py::class_<td_api::chatEventMessageTtlSettingChanged>(m, "chatEventMessageTtlSettingChanged")
            .def(py::init<>())
    
            .def_readwrite("old_message_ttl_setting", &td_api::chatEventMessageTtlSettingChanged::old_message_ttl_setting_)
            .def_readwrite("new_message_ttl_setting", &td_api::chatEventMessageTtlSettingChanged::new_message_ttl_setting_);
    
    // The sign_messages setting of a channel was toggled @sign_messages New value of sign_messages
    py::class_<td_api::chatEventSignMessagesToggled>(m, "chatEventSignMessagesToggled")
            .def(py::init<>())
    
            .def_readwrite("sign_messages", &td_api::chatEventSignMessagesToggled::sign_messages_);
    
    // The supergroup sticker set was changed @old_sticker_set_id Previous identifier of the chat sticker set; 0 if none @new_sticker_set_id New identifier of the chat sticker set; 0 if none
    py::class_<td_api::chatEventStickerSetChanged>(m, "chatEventStickerSetChanged")
            .def(py::init<>())
    
            .def_readwrite("old_sticker_set_id", &td_api::chatEventStickerSetChanged::old_sticker_set_id_)
            .def_readwrite("new_sticker_set_id", &td_api::chatEventStickerSetChanged::new_sticker_set_id_);
    
    // The supergroup location was changed @old_location Previous location; may be null @new_location New location; may be null
    py::class_<td_api::chatEventLocationChanged>(m, "chatEventLocationChanged")
            .def(py::init<>())
    
            .def_readwrite("old_location", &td_api::chatEventLocationChanged::old_location_)
            .def_readwrite("new_location", &td_api::chatEventLocationChanged::new_location_);
    
    // The is_all_history_available setting of a supergroup was toggled @is_all_history_available New value of is_all_history_available
    py::class_<td_api::chatEventIsAllHistoryAvailableToggled>(m, "chatEventIsAllHistoryAvailableToggled")
            .def(py::init<>())
    
            .def_readwrite("is_all_history_available", &td_api::chatEventIsAllHistoryAvailableToggled::is_all_history_available_);
    
    // A chat invite link was edited @old_invite_link Previous information about the invite link @new_invite_link New information about the invite link
    py::class_<td_api::chatEventInviteLinkEdited>(m, "chatEventInviteLinkEdited")
            .def(py::init<>())
    
            .def_readwrite("old_invite_link", &td_api::chatEventInviteLinkEdited::old_invite_link_)
            .def_readwrite("new_invite_link", &td_api::chatEventInviteLinkEdited::new_invite_link_);
    
    // A chat invite link was revoked @invite_link The invite link
    py::class_<td_api::chatEventInviteLinkRevoked>(m, "chatEventInviteLinkRevoked")
            .def(py::init<>())
    
            .def_readwrite("invite_link", &td_api::chatEventInviteLinkRevoked::invite_link_);
    
    // A revoked chat invite link was deleted @invite_link The invite link
    py::class_<td_api::chatEventInviteLinkDeleted>(m, "chatEventInviteLinkDeleted")
            .def(py::init<>())
    
            .def_readwrite("invite_link", &td_api::chatEventInviteLinkDeleted::invite_link_);
    
    // A voice chat was created @group_call_id Identifier of the voice chat. The voice chat can be received through the method getGroupCall
    py::class_<td_api::chatEventVoiceChatCreated>(m, "chatEventVoiceChatCreated")
            .def(py::init<>())
    
            .def_readwrite("group_call_id", &td_api::chatEventVoiceChatCreated::group_call_id_);
    
    // A voice chat was discarded @group_call_id Identifier of the voice chat. The voice chat can be received through the method getGroupCall
    py::class_<td_api::chatEventVoiceChatDiscarded>(m, "chatEventVoiceChatDiscarded")
            .def(py::init<>())
    
            .def_readwrite("group_call_id", &td_api::chatEventVoiceChatDiscarded::group_call_id_);
    
    // A voice chat participant was muted or unmuted @participant_id Identifier of the affected group call participant @is_muted New value of is_muted
    py::class_<td_api::chatEventVoiceChatParticipantIsMutedToggled>(m, "chatEventVoiceChatParticipantIsMutedToggled")
            .def(py::init<>())
    
            .def_readwrite("participant_id", &td_api::chatEventVoiceChatParticipantIsMutedToggled::participant_id_)
            .def_readwrite("is_muted", &td_api::chatEventVoiceChatParticipantIsMutedToggled::is_muted_);
    
    // A voice chat participant volume level was changed @participant_id Identifier of the affected group call participant @volume_level New value of volume_level; 1-20000 in hundreds of percents
    py::class_<td_api::chatEventVoiceChatParticipantVolumeLevelChanged>(m, "chatEventVoiceChatParticipantVolumeLevelChanged")
            .def(py::init<>())
    
            .def_readwrite("participant_id", &td_api::chatEventVoiceChatParticipantVolumeLevelChanged::participant_id_)
            .def_readwrite("volume_level", &td_api::chatEventVoiceChatParticipantVolumeLevelChanged::volume_level_);
    
    // The mute_new_participants setting of a voice chat was toggled @mute_new_participants New value of the mute_new_participants setting
    py::class_<td_api::chatEventVoiceChatMuteNewParticipantsToggled>(m, "chatEventVoiceChatMuteNewParticipantsToggled")
            .def(py::init<>())
    
            .def_readwrite("mute_new_participants", &td_api::chatEventVoiceChatMuteNewParticipantsToggled::mute_new_participants_);
    
    // Represents a chat event @id Chat event identifier @date Point in time (Unix timestamp) when the event happened @user_id Identifier of the user who performed the action that triggered the event @action Action performed by the user
    py::class_<td_api::chatEvent>(m, "chatEvent")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::chatEvent::id_)
            .def_readwrite("date", &td_api::chatEvent::date_)
            .def_readwrite("user_id", &td_api::chatEvent::user_id_)
            .def_readwrite("action", &td_api::chatEvent::action_);
    
    // Contains a list of chat events @events List of events
    py::class_<td_api::chatEvents>(m, "chatEvents")
            .def(py::init<>())
    
            .def_readwrite("events", &td_api::chatEvents::events_);
    
    // Represents a set of filters used to obtain a chat event log
    py::class_<td_api::chatEventLogFilters>(m, "chatEventLogFilters")
            .def(py::init<>())
    
            .def_readwrite("message_edits", &td_api::chatEventLogFilters::message_edits_)
            .def_readwrite("message_deletions", &td_api::chatEventLogFilters::message_deletions_)
            .def_readwrite("message_pins", &td_api::chatEventLogFilters::message_pins_)
            .def_readwrite("member_joins", &td_api::chatEventLogFilters::member_joins_)
            .def_readwrite("member_leaves", &td_api::chatEventLogFilters::member_leaves_)
            .def_readwrite("member_invites", &td_api::chatEventLogFilters::member_invites_)
            .def_readwrite("member_promotions", &td_api::chatEventLogFilters::member_promotions_)
            .def_readwrite("member_restrictions", &td_api::chatEventLogFilters::member_restrictions_)
            .def_readwrite("info_changes", &td_api::chatEventLogFilters::info_changes_)
            .def_readwrite("setting_changes", &td_api::chatEventLogFilters::setting_changes_)
            .def_readwrite("invite_link_changes", &td_api::chatEventLogFilters::invite_link_changes_)
            .def_readwrite("voice_chat_changes", &td_api::chatEventLogFilters::voice_chat_changes_);
    
    // An ordinary language pack string @value String value
    py::class_<td_api::languagePackStringValueOrdinary>(m, "languagePackStringValueOrdinary")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::languagePackStringValueOrdinary::value_);
    
    // A language pack string which has different forms based on the number of some object it mentions. See https://www.unicode.org/cldr/charts/latest/supplemental/language_plural_rules.html for more info
    py::class_<td_api::languagePackStringValuePluralized>(m, "languagePackStringValuePluralized")
            .def(py::init<>())
    
            .def_readwrite("zero_value", &td_api::languagePackStringValuePluralized::zero_value_)
            .def_readwrite("one_value", &td_api::languagePackStringValuePluralized::one_value_)
            .def_readwrite("two_value", &td_api::languagePackStringValuePluralized::two_value_)
            .def_readwrite("few_value", &td_api::languagePackStringValuePluralized::few_value_)
            .def_readwrite("many_value", &td_api::languagePackStringValuePluralized::many_value_)
            .def_readwrite("other_value", &td_api::languagePackStringValuePluralized::other_value_);
    
    // A deleted language pack string, the value should be taken from the built-in english language pack
    py::class_<td_api::languagePackStringValueDeleted>(m, "languagePackStringValueDeleted")
            .def(py::init<>());
    
    // Represents one language pack string @key String key @value String value
    py::class_<td_api::languagePackString>(m, "languagePackString")
            .def(py::init<>())
    
            .def_readwrite("key", &td_api::languagePackString::key_)
            .def_readwrite("value", &td_api::languagePackString::value_);
    
    // Contains a list of language pack strings @strings A list of language pack strings
    py::class_<td_api::languagePackStrings>(m, "languagePackStrings")
            .def(py::init<>())
    
            .def_readwrite("strings", &td_api::languagePackStrings::strings_);
    
    // Contains information about a language pack @id Unique language pack identifier
    py::class_<td_api::languagePackInfo>(m, "languagePackInfo")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::languagePackInfo::id_)
            .def_readwrite("base_language_pack_id", &td_api::languagePackInfo::base_language_pack_id_)
            .def_readwrite("name", &td_api::languagePackInfo::name_)
            .def_readwrite("native_name", &td_api::languagePackInfo::native_name_)
            .def_readwrite("plural_code", &td_api::languagePackInfo::plural_code_)
            .def_readwrite("is_official", &td_api::languagePackInfo::is_official_)
            .def_readwrite("is_rtl", &td_api::languagePackInfo::is_rtl_)
            .def_readwrite("is_beta", &td_api::languagePackInfo::is_beta_)
            .def_readwrite("is_installed", &td_api::languagePackInfo::is_installed_)
            .def_readwrite("total_string_count", &td_api::languagePackInfo::total_string_count_)
            .def_readwrite("translated_string_count", &td_api::languagePackInfo::translated_string_count_)
            .def_readwrite("local_string_count", &td_api::languagePackInfo::local_string_count_)
            .def_readwrite("translation_url", &td_api::languagePackInfo::translation_url_);
    
    // Contains information about the current localization target @language_packs List of available language packs for this application
    py::class_<td_api::localizationTargetInfo>(m, "localizationTargetInfo")
            .def(py::init<>())
    
            .def_readwrite("language_packs", &td_api::localizationTargetInfo::language_packs_);
    
    // A token for Firebase Cloud Messaging @token Device registration token; may be empty to de-register a device @encrypt True, if push notifications should be additionally encrypted
    py::class_<td_api::deviceTokenFirebaseCloudMessaging>(m, "deviceTokenFirebaseCloudMessaging")
            .def(py::init<>())
    
            .def_readwrite("token", &td_api::deviceTokenFirebaseCloudMessaging::token_)
            .def_readwrite("encrypt", &td_api::deviceTokenFirebaseCloudMessaging::encrypt_);
    
    // A token for Apple Push Notification service @device_token Device token; may be empty to de-register a device @is_app_sandbox True, if App Sandbox is enabled
    py::class_<td_api::deviceTokenApplePush>(m, "deviceTokenApplePush")
            .def(py::init<>())
    
            .def_readwrite("device_token", &td_api::deviceTokenApplePush::device_token_)
            .def_readwrite("is_app_sandbox", &td_api::deviceTokenApplePush::is_app_sandbox_);
    
    // A token for Apple Push Notification service VoIP notifications @device_token Device token; may be empty to de-register a device @is_app_sandbox True, if App Sandbox is enabled @encrypt True, if push notifications should be additionally encrypted
    py::class_<td_api::deviceTokenApplePushVoIP>(m, "deviceTokenApplePushVoIP")
            .def(py::init<>())
    
            .def_readwrite("device_token", &td_api::deviceTokenApplePushVoIP::device_token_)
            .def_readwrite("is_app_sandbox", &td_api::deviceTokenApplePushVoIP::is_app_sandbox_)
            .def_readwrite("encrypt", &td_api::deviceTokenApplePushVoIP::encrypt_);
    
    // A token for Windows Push Notification Services @access_token The access token that will be used to send notifications; may be empty to de-register a device
    py::class_<td_api::deviceTokenWindowsPush>(m, "deviceTokenWindowsPush")
            .def(py::init<>())
    
            .def_readwrite("access_token", &td_api::deviceTokenWindowsPush::access_token_);
    
    // A token for Microsoft Push Notification Service @channel_uri Push notification channel URI; may be empty to de-register a device
    py::class_<td_api::deviceTokenMicrosoftPush>(m, "deviceTokenMicrosoftPush")
            .def(py::init<>())
    
            .def_readwrite("channel_uri", &td_api::deviceTokenMicrosoftPush::channel_uri_);
    
    // A token for Microsoft Push Notification Service VoIP channel @channel_uri Push notification channel URI; may be empty to de-register a device
    py::class_<td_api::deviceTokenMicrosoftPushVoIP>(m, "deviceTokenMicrosoftPushVoIP")
            .def(py::init<>())
    
            .def_readwrite("channel_uri", &td_api::deviceTokenMicrosoftPushVoIP::channel_uri_);
    
    // A token for web Push API @endpoint Absolute URL exposed by the push service where the application server can send push messages; may be empty to de-register a device
    py::class_<td_api::deviceTokenWebPush>(m, "deviceTokenWebPush")
            .def(py::init<>())
    
            .def_readwrite("endpoint", &td_api::deviceTokenWebPush::endpoint_)
            .def_readwrite("p256dh_base64url", &td_api::deviceTokenWebPush::p256dh_base64url_)
            .def_readwrite("auth_base64url", &td_api::deviceTokenWebPush::auth_base64url_);
    
    // A token for Simple Push API for Firefox OS @endpoint Absolute URL exposed by the push service where the application server can send push messages; may be empty to de-register a device
    py::class_<td_api::deviceTokenSimplePush>(m, "deviceTokenSimplePush")
            .def(py::init<>())
    
            .def_readwrite("endpoint", &td_api::deviceTokenSimplePush::endpoint_);
    
    // A token for Ubuntu Push Client service @token Token; may be empty to de-register a device
    py::class_<td_api::deviceTokenUbuntuPush>(m, "deviceTokenUbuntuPush")
            .def(py::init<>())
    
            .def_readwrite("token", &td_api::deviceTokenUbuntuPush::token_);
    
    // A token for BlackBerry Push Service @token Token; may be empty to de-register a device
    py::class_<td_api::deviceTokenBlackBerryPush>(m, "deviceTokenBlackBerryPush")
            .def(py::init<>())
    
            .def_readwrite("token", &td_api::deviceTokenBlackBerryPush::token_);
    
    // A token for Tizen Push Service @reg_id Push service registration identifier; may be empty to de-register a device
    py::class_<td_api::deviceTokenTizenPush>(m, "deviceTokenTizenPush")
            .def(py::init<>())
    
            .def_readwrite("reg_id", &td_api::deviceTokenTizenPush::reg_id_);
    
    // Contains a globally unique push receiver identifier, which can be used to identify which account has received a push notification @id The globally unique identifier of push notification subscription
    py::class_<td_api::pushReceiverId>(m, "pushReceiverId")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::pushReceiverId::id_);
    
    // Describes a solid fill of a background @color A color of the background in the RGB24 format
    py::class_<td_api::backgroundFillSolid>(m, "backgroundFillSolid")
            .def(py::init<>())
    
            .def_readwrite("color", &td_api::backgroundFillSolid::color_);
    
    // Describes a gradient fill of a background @top_color A top color of the background in the RGB24 format @bottom_color A bottom color of the background in the RGB24 format
    py::class_<td_api::backgroundFillGradient>(m, "backgroundFillGradient")
            .def(py::init<>())
    
            .def_readwrite("top_color", &td_api::backgroundFillGradient::top_color_)
            .def_readwrite("bottom_color", &td_api::backgroundFillGradient::bottom_color_)
            .def_readwrite("rotation_angle", &td_api::backgroundFillGradient::rotation_angle_);
    
    // Describes a freeform gradient fill of a background @colors A list of 3 or 4 colors of the freeform gradients in the RGB24 format
    py::class_<td_api::backgroundFillFreeformGradient>(m, "backgroundFillFreeformGradient")
            .def(py::init<>())
    
            .def_readwrite("colors", &td_api::backgroundFillFreeformGradient::colors_);
    
    // A wallpaper in JPEG format
    py::class_<td_api::backgroundTypeWallpaper>(m, "backgroundTypeWallpaper")
            .def(py::init<>())
    
            .def_readwrite("is_blurred", &td_api::backgroundTypeWallpaper::is_blurred_)
            .def_readwrite("is_moving", &td_api::backgroundTypeWallpaper::is_moving_);
    
    // A PNG or TGV (gzipped subset of SVG with MIME type "application/x-tgwallpattern") pattern to be combined with the background fill chosen by the user
    py::class_<td_api::backgroundTypePattern>(m, "backgroundTypePattern")
            .def(py::init<>())
    
            .def_readwrite("fill", &td_api::backgroundTypePattern::fill_)
            .def_readwrite("intensity", &td_api::backgroundTypePattern::intensity_)
            .def_readwrite("is_moving", &td_api::backgroundTypePattern::is_moving_);
    
    // A filled background @fill Description of the background fill
    py::class_<td_api::backgroundTypeFill>(m, "backgroundTypeFill")
            .def(py::init<>())
    
            .def_readwrite("fill", &td_api::backgroundTypeFill::fill_);
    
    // Describes a chat background
    py::class_<td_api::background>(m, "background")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::background::id_)
            .def_readwrite("is_default", &td_api::background::is_default_)
            .def_readwrite("is_dark", &td_api::background::is_dark_)
            .def_readwrite("name", &td_api::background::name_)
            .def_readwrite("document", &td_api::background::document_)
            .def_readwrite("type", &td_api::background::type_);
    
    // Contains a list of backgrounds @backgrounds A list of backgrounds
    py::class_<td_api::backgrounds>(m, "backgrounds")
            .def(py::init<>())
    
            .def_readwrite("backgrounds", &td_api::backgrounds::backgrounds_);
    
    // A background from a local file
    py::class_<td_api::inputBackgroundLocal>(m, "inputBackgroundLocal")
            .def(py::init<>())
    
            .def_readwrite("background", &td_api::inputBackgroundLocal::background_);
    
    // A background from the server @background_id The background identifier
    py::class_<td_api::inputBackgroundRemote>(m, "inputBackgroundRemote")
            .def(py::init<>())
    
            .def_readwrite("background_id", &td_api::inputBackgroundRemote::background_id_);
    
    // Contains a list of hashtags @hashtags A list of hashtags
    py::class_<td_api::hashtags>(m, "hashtags")
            .def(py::init<>())
    
            .def_readwrite("hashtags", &td_api::hashtags::hashtags_);
    
    // The session can be used
    py::class_<td_api::canTransferOwnershipResultOk>(m, "canTransferOwnershipResultOk")
            .def(py::init<>());
    
    // The 2-step verification needs to be enabled first
    py::class_<td_api::canTransferOwnershipResultPasswordNeeded>(m, "canTransferOwnershipResultPasswordNeeded")
            .def(py::init<>());
    
    // The 2-step verification was enabled recently, user needs to wait @retry_after Time left before the session can be used to transfer ownership of a chat, in seconds
    py::class_<td_api::canTransferOwnershipResultPasswordTooFresh>(m, "canTransferOwnershipResultPasswordTooFresh")
            .def(py::init<>())
    
            .def_readwrite("retry_after", &td_api::canTransferOwnershipResultPasswordTooFresh::retry_after_);
    
    // The session was created recently, user needs to wait @retry_after Time left before the session can be used to transfer ownership of a chat, in seconds
    py::class_<td_api::canTransferOwnershipResultSessionTooFresh>(m, "canTransferOwnershipResultSessionTooFresh")
            .def(py::init<>())
    
            .def_readwrite("retry_after", &td_api::canTransferOwnershipResultSessionTooFresh::retry_after_);
    
    // The username can be set
    py::class_<td_api::checkChatUsernameResultOk>(m, "checkChatUsernameResultOk")
            .def(py::init<>());
    
    // The username is invalid
    py::class_<td_api::checkChatUsernameResultUsernameInvalid>(m, "checkChatUsernameResultUsernameInvalid")
            .def(py::init<>());
    
    // The username is occupied
    py::class_<td_api::checkChatUsernameResultUsernameOccupied>(m, "checkChatUsernameResultUsernameOccupied")
            .def(py::init<>());
    
    // The user has too much chats with username, one of them should be made private first
    py::class_<td_api::checkChatUsernameResultPublicChatsTooMuch>(m, "checkChatUsernameResultPublicChatsTooMuch")
            .def(py::init<>());
    
    // The user can't be a member of a public supergroup
    py::class_<td_api::checkChatUsernameResultPublicGroupsUnavailable>(m, "checkChatUsernameResultPublicGroupsUnavailable")
            .def(py::init<>());
    
    // The name can be set
    py::class_<td_api::checkStickerSetNameResultOk>(m, "checkStickerSetNameResultOk")
            .def(py::init<>());
    
    // The name is invalid
    py::class_<td_api::checkStickerSetNameResultNameInvalid>(m, "checkStickerSetNameResultNameInvalid")
            .def(py::init<>());
    
    // The name is occupied
    py::class_<td_api::checkStickerSetNameResultNameOccupied>(m, "checkStickerSetNameResultNameOccupied")
            .def(py::init<>());
    
    // The password was reset
    py::class_<td_api::resetPasswordResultOk>(m, "resetPasswordResultOk")
            .def(py::init<>());
    
    // The password reset request is pending @pending_reset_date Point in time (Unix timestamp) after which the password can be reset immediately using resetPassword
    py::class_<td_api::resetPasswordResultPending>(m, "resetPasswordResultPending")
            .def(py::init<>())
    
            .def_readwrite("pending_reset_date", &td_api::resetPasswordResultPending::pending_reset_date_);
    
    // The password reset request was declined @retry_date Point in time (Unix timestamp) when the password reset can be retried
    py::class_<td_api::resetPasswordResultDeclined>(m, "resetPasswordResultDeclined")
            .def(py::init<>())
    
            .def_readwrite("retry_date", &td_api::resetPasswordResultDeclined::retry_date_);
    
    // The messages was exported from a private chat @name Name of the other party; may be empty if unrecognized
    py::class_<td_api::messageFileTypePrivate>(m, "messageFileTypePrivate")
            .def(py::init<>())
    
            .def_readwrite("name", &td_api::messageFileTypePrivate::name_);
    
    // The messages was exported from a group chat @title Title of the group chat; may be empty if unrecognized
    py::class_<td_api::messageFileTypeGroup>(m, "messageFileTypeGroup")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::messageFileTypeGroup::title_);
    
    // The messages was exported from a chat of unknown type
    py::class_<td_api::messageFileTypeUnknown>(m, "messageFileTypeUnknown")
            .def(py::init<>());
    
    // A general message with hidden content @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentHidden>(m, "pushMessageContentHidden")
            .def(py::init<>())
    
            .def_readwrite("is_pinned", &td_api::pushMessageContentHidden::is_pinned_);
    
    // An animation message (GIF-style). @animation Message content; may be null @caption Animation caption @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentAnimation>(m, "pushMessageContentAnimation")
            .def(py::init<>())
    
            .def_readwrite("animation", &td_api::pushMessageContentAnimation::animation_)
            .def_readwrite("caption", &td_api::pushMessageContentAnimation::caption_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentAnimation::is_pinned_);
    
    // An audio message @audio Message content; may be null @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentAudio>(m, "pushMessageContentAudio")
            .def(py::init<>())
    
            .def_readwrite("audio", &td_api::pushMessageContentAudio::audio_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentAudio::is_pinned_);
    
    // A message with a user contact @name Contact's name @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentContact>(m, "pushMessageContentContact")
            .def(py::init<>())
    
            .def_readwrite("name", &td_api::pushMessageContentContact::name_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentContact::is_pinned_);
    
    // A contact has registered with Telegram
    py::class_<td_api::pushMessageContentContactRegistered>(m, "pushMessageContentContactRegistered")
            .def(py::init<>());
    
    // A document message (a general file) @document Message content; may be null @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentDocument>(m, "pushMessageContentDocument")
            .def(py::init<>())
    
            .def_readwrite("document", &td_api::pushMessageContentDocument::document_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentDocument::is_pinned_);
    
    // A message with a game @title Game title, empty for pinned game message @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentGame>(m, "pushMessageContentGame")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::pushMessageContentGame::title_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentGame::is_pinned_);
    
    // A new high score was achieved in a game @title Game title, empty for pinned message @score New score, 0 for pinned message @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentGameScore>(m, "pushMessageContentGameScore")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::pushMessageContentGameScore::title_)
            .def_readwrite("score", &td_api::pushMessageContentGameScore::score_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentGameScore::is_pinned_);
    
    // A message with an invoice from a bot @price Product price @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentInvoice>(m, "pushMessageContentInvoice")
            .def(py::init<>())
    
            .def_readwrite("price", &td_api::pushMessageContentInvoice::price_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentInvoice::is_pinned_);
    
    // A message with a location @is_live True, if the location is live @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentLocation>(m, "pushMessageContentLocation")
            .def(py::init<>())
    
            .def_readwrite("is_live", &td_api::pushMessageContentLocation::is_live_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentLocation::is_pinned_);
    
    // A photo message @photo Message content; may be null @caption Photo caption @is_secret True, if the photo is secret @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentPhoto>(m, "pushMessageContentPhoto")
            .def(py::init<>())
    
            .def_readwrite("photo", &td_api::pushMessageContentPhoto::photo_)
            .def_readwrite("caption", &td_api::pushMessageContentPhoto::caption_)
            .def_readwrite("is_secret", &td_api::pushMessageContentPhoto::is_secret_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentPhoto::is_pinned_);
    
    // A message with a poll @question Poll question @is_regular True, if the poll is regular and not in quiz mode @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentPoll>(m, "pushMessageContentPoll")
            .def(py::init<>())
    
            .def_readwrite("question", &td_api::pushMessageContentPoll::question_)
            .def_readwrite("is_regular", &td_api::pushMessageContentPoll::is_regular_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentPoll::is_pinned_);
    
    // A screenshot of a message in the chat has been taken
    py::class_<td_api::pushMessageContentScreenshotTaken>(m, "pushMessageContentScreenshotTaken")
            .def(py::init<>());
    
    // A message with a sticker @sticker Message content; may be null @emoji Emoji corresponding to the sticker; may be empty @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentSticker>(m, "pushMessageContentSticker")
            .def(py::init<>())
    
            .def_readwrite("sticker", &td_api::pushMessageContentSticker::sticker_)
            .def_readwrite("emoji", &td_api::pushMessageContentSticker::emoji_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentSticker::is_pinned_);
    
    // A text message @text Message text @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentText>(m, "pushMessageContentText")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::pushMessageContentText::text_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentText::is_pinned_);
    
    // A video message @video Message content; may be null @caption Video caption @is_secret True, if the video is secret @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentVideo>(m, "pushMessageContentVideo")
            .def(py::init<>())
    
            .def_readwrite("video", &td_api::pushMessageContentVideo::video_)
            .def_readwrite("caption", &td_api::pushMessageContentVideo::caption_)
            .def_readwrite("is_secret", &td_api::pushMessageContentVideo::is_secret_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentVideo::is_pinned_);
    
    // A video note message @video_note Message content; may be null @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentVideoNote>(m, "pushMessageContentVideoNote")
            .def(py::init<>())
    
            .def_readwrite("video_note", &td_api::pushMessageContentVideoNote::video_note_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentVideoNote::is_pinned_);
    
    // A voice note message @voice_note Message content; may be null @is_pinned True, if the message is a pinned message with the specified content
    py::class_<td_api::pushMessageContentVoiceNote>(m, "pushMessageContentVoiceNote")
            .def(py::init<>())
    
            .def_readwrite("voice_note", &td_api::pushMessageContentVoiceNote::voice_note_)
            .def_readwrite("is_pinned", &td_api::pushMessageContentVoiceNote::is_pinned_);
    
    // A newly created basic group
    py::class_<td_api::pushMessageContentBasicGroupChatCreate>(m, "pushMessageContentBasicGroupChatCreate")
            .def(py::init<>());
    
    // New chat members were invited to a group @member_name Name of the added member @is_current_user True, if the current user was added to the group
    py::class_<td_api::pushMessageContentChatAddMembers>(m, "pushMessageContentChatAddMembers")
            .def(py::init<>())
    
            .def_readwrite("member_name", &td_api::pushMessageContentChatAddMembers::member_name_)
            .def_readwrite("is_current_user", &td_api::pushMessageContentChatAddMembers::is_current_user_)
            .def_readwrite("is_returned", &td_api::pushMessageContentChatAddMembers::is_returned_);
    
    // A chat photo was edited
    py::class_<td_api::pushMessageContentChatChangePhoto>(m, "pushMessageContentChatChangePhoto")
            .def(py::init<>());
    
    // A chat title was edited @title New chat title
    py::class_<td_api::pushMessageContentChatChangeTitle>(m, "pushMessageContentChatChangeTitle")
            .def(py::init<>())
    
            .def_readwrite("title", &td_api::pushMessageContentChatChangeTitle::title_);
    
    // A chat member was deleted @member_name Name of the deleted member @is_current_user True, if the current user was deleted from the group
    py::class_<td_api::pushMessageContentChatDeleteMember>(m, "pushMessageContentChatDeleteMember")
            .def(py::init<>())
    
            .def_readwrite("member_name", &td_api::pushMessageContentChatDeleteMember::member_name_)
            .def_readwrite("is_current_user", &td_api::pushMessageContentChatDeleteMember::is_current_user_)
            .def_readwrite("is_left", &td_api::pushMessageContentChatDeleteMember::is_left_);
    
    // A new member joined the chat by invite link
    py::class_<td_api::pushMessageContentChatJoinByLink>(m, "pushMessageContentChatJoinByLink")
            .def(py::init<>());
    
    // A forwarded messages @total_count Number of forwarded messages
    py::class_<td_api::pushMessageContentMessageForwards>(m, "pushMessageContentMessageForwards")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::pushMessageContentMessageForwards::total_count_);
    
    // A media album @total_count Number of messages in the album @has_photos True, if the album has at least one photo @has_videos True, if the album has at least one video
    py::class_<td_api::pushMessageContentMediaAlbum>(m, "pushMessageContentMediaAlbum")
            .def(py::init<>())
    
            .def_readwrite("total_count", &td_api::pushMessageContentMediaAlbum::total_count_)
            .def_readwrite("has_photos", &td_api::pushMessageContentMediaAlbum::has_photos_)
            .def_readwrite("has_videos", &td_api::pushMessageContentMediaAlbum::has_videos_)
            .def_readwrite("has_audios", &td_api::pushMessageContentMediaAlbum::has_audios_)
            .def_readwrite("has_documents", &td_api::pushMessageContentMediaAlbum::has_documents_);
    
    // New message was received @message The message
    py::class_<td_api::notificationTypeNewMessage>(m, "notificationTypeNewMessage")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::notificationTypeNewMessage::message_);
    
    // New secret chat was created
    py::class_<td_api::notificationTypeNewSecretChat>(m, "notificationTypeNewSecretChat")
            .def(py::init<>());
    
    // New call was received @call_id Call identifier
    py::class_<td_api::notificationTypeNewCall>(m, "notificationTypeNewCall")
            .def(py::init<>())
    
            .def_readwrite("call_id", &td_api::notificationTypeNewCall::call_id_);
    
    // New message was received through a push notification
    py::class_<td_api::notificationTypeNewPushMessage>(m, "notificationTypeNewPushMessage")
            .def(py::init<>())
    
            .def_readwrite("message_id", &td_api::notificationTypeNewPushMessage::message_id_)
            .def_readwrite("sender", &td_api::notificationTypeNewPushMessage::sender_)
            .def_readwrite("sender_name", &td_api::notificationTypeNewPushMessage::sender_name_)
            .def_readwrite("is_outgoing", &td_api::notificationTypeNewPushMessage::is_outgoing_)
            .def_readwrite("content", &td_api::notificationTypeNewPushMessage::content_);
    
    // A group containing notifications of type notificationTypeNewMessage and notificationTypeNewPushMessage with ordinary unread messages
    py::class_<td_api::notificationGroupTypeMessages>(m, "notificationGroupTypeMessages")
            .def(py::init<>());
    
    // A group containing notifications of type notificationTypeNewMessage and notificationTypeNewPushMessage with unread mentions of the current user, replies to their messages, or a pinned message
    py::class_<td_api::notificationGroupTypeMentions>(m, "notificationGroupTypeMentions")
            .def(py::init<>());
    
    // A group containing a notification of type notificationTypeNewSecretChat
    py::class_<td_api::notificationGroupTypeSecretChat>(m, "notificationGroupTypeSecretChat")
            .def(py::init<>());
    
    // A group containing notifications of type notificationTypeNewCall
    py::class_<td_api::notificationGroupTypeCalls>(m, "notificationGroupTypeCalls")
            .def(py::init<>());
    
    // Contains information about a notification @id Unique persistent identifier of this notification @date Notification date
    py::class_<td_api::notification>(m, "notification")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::notification::id_)
            .def_readwrite("date", &td_api::notification::date_)
            .def_readwrite("is_silent", &td_api::notification::is_silent_)
            .def_readwrite("type", &td_api::notification::type_);
    
    // Describes a group of notifications @id Unique persistent auto-incremented from 1 identifier of the notification group @type Type of the group
    py::class_<td_api::notificationGroup>(m, "notificationGroup")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::notificationGroup::id_)
            .def_readwrite("type", &td_api::notificationGroup::type_)
            .def_readwrite("chat_id", &td_api::notificationGroup::chat_id_)
            .def_readwrite("total_count", &td_api::notificationGroup::total_count_)
            .def_readwrite("notifications", &td_api::notificationGroup::notifications_);
    
    // Represents a boolean option @value The value of the option
    py::class_<td_api::optionValueBoolean>(m, "optionValueBoolean")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::optionValueBoolean::value_);
    
    // Represents an unknown option or an option which has a default value
    py::class_<td_api::optionValueEmpty>(m, "optionValueEmpty")
            .def(py::init<>());
    
    // Represents an integer option @value The value of the option
    py::class_<td_api::optionValueInteger>(m, "optionValueInteger")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::optionValueInteger::value_);
    
    // Represents a string option @value The value of the option
    py::class_<td_api::optionValueString>(m, "optionValueString")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::optionValueString::value_);
    
    // Represents one member of a JSON object @key Member's key @value Member's value
    py::class_<td_api::jsonObjectMember>(m, "jsonObjectMember")
            .def(py::init<>())
    
            .def_readwrite("key", &td_api::jsonObjectMember::key_)
            .def_readwrite("value", &td_api::jsonObjectMember::value_);
    
    // Represents a null JSON value
    py::class_<td_api::jsonValueNull>(m, "jsonValueNull")
            .def(py::init<>());
    
    // Represents a boolean JSON value @value The value
    py::class_<td_api::jsonValueBoolean>(m, "jsonValueBoolean")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::jsonValueBoolean::value_);
    
    // Represents a numeric JSON value @value The value
    py::class_<td_api::jsonValueNumber>(m, "jsonValueNumber")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::jsonValueNumber::value_);
    
    // Represents a string JSON value @value The value
    py::class_<td_api::jsonValueString>(m, "jsonValueString")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::jsonValueString::value_);
    
    // Represents a JSON array @values The list of array elements
    py::class_<td_api::jsonValueArray>(m, "jsonValueArray")
            .def(py::init<>())
    
            .def_readwrite("values", &td_api::jsonValueArray::values_);
    
    // Represents a JSON object @members The list of object members
    py::class_<td_api::jsonValueObject>(m, "jsonValueObject")
            .def(py::init<>())
    
            .def_readwrite("members", &td_api::jsonValueObject::members_);
    
    // A rule to allow all users to do something
    py::class_<td_api::userPrivacySettingRuleAllowAll>(m, "userPrivacySettingRuleAllowAll")
            .def(py::init<>());
    
    // A rule to allow all of a user's contacts to do something
    py::class_<td_api::userPrivacySettingRuleAllowContacts>(m, "userPrivacySettingRuleAllowContacts")
            .def(py::init<>());
    
    // A rule to allow certain specified users to do something @user_ids The user identifiers, total number of users in all rules must not exceed 1000
    py::class_<td_api::userPrivacySettingRuleAllowUsers>(m, "userPrivacySettingRuleAllowUsers")
            .def(py::init<>())
    
            .def_readwrite("user_ids", &td_api::userPrivacySettingRuleAllowUsers::user_ids_);
    
    // A rule to allow all members of certain specified basic groups and supergroups to doing something @chat_ids The chat identifiers, total number of chats in all rules must not exceed 20
    py::class_<td_api::userPrivacySettingRuleAllowChatMembers>(m, "userPrivacySettingRuleAllowChatMembers")
            .def(py::init<>())
    
            .def_readwrite("chat_ids", &td_api::userPrivacySettingRuleAllowChatMembers::chat_ids_);
    
    // A rule to restrict all users from doing something
    py::class_<td_api::userPrivacySettingRuleRestrictAll>(m, "userPrivacySettingRuleRestrictAll")
            .def(py::init<>());
    
    // A rule to restrict all contacts of a user from doing something
    py::class_<td_api::userPrivacySettingRuleRestrictContacts>(m, "userPrivacySettingRuleRestrictContacts")
            .def(py::init<>());
    
    // A rule to restrict all specified users from doing something @user_ids The user identifiers, total number of users in all rules must not exceed 1000
    py::class_<td_api::userPrivacySettingRuleRestrictUsers>(m, "userPrivacySettingRuleRestrictUsers")
            .def(py::init<>())
    
            .def_readwrite("user_ids", &td_api::userPrivacySettingRuleRestrictUsers::user_ids_);
    
    // A rule to restrict all members of specified basic groups and supergroups from doing something @chat_ids The chat identifiers, total number of chats in all rules must not exceed 20
    py::class_<td_api::userPrivacySettingRuleRestrictChatMembers>(m, "userPrivacySettingRuleRestrictChatMembers")
            .def(py::init<>())
    
            .def_readwrite("chat_ids", &td_api::userPrivacySettingRuleRestrictChatMembers::chat_ids_);
    
    // A list of privacy rules. Rules are matched in the specified order. The first matched rule defines the privacy setting for a given user. If no rule matches, the action is not allowed @rules A list of rules
    py::class_<td_api::userPrivacySettingRules>(m, "userPrivacySettingRules")
            .def(py::init<>())
    
            .def_readwrite("rules", &td_api::userPrivacySettingRules::rules_);
    
    // A privacy setting for managing whether the user's online status is visible
    py::class_<td_api::userPrivacySettingShowStatus>(m, "userPrivacySettingShowStatus")
            .def(py::init<>());
    
    // A privacy setting for managing whether the user's profile photo is visible
    py::class_<td_api::userPrivacySettingShowProfilePhoto>(m, "userPrivacySettingShowProfilePhoto")
            .def(py::init<>());
    
    // A privacy setting for managing whether a link to the user's account is included in forwarded messages
    py::class_<td_api::userPrivacySettingShowLinkInForwardedMessages>(m, "userPrivacySettingShowLinkInForwardedMessages")
            .def(py::init<>());
    
    // A privacy setting for managing whether the user's phone number is visible
    py::class_<td_api::userPrivacySettingShowPhoneNumber>(m, "userPrivacySettingShowPhoneNumber")
            .def(py::init<>());
    
    // A privacy setting for managing whether the user can be invited to chats
    py::class_<td_api::userPrivacySettingAllowChatInvites>(m, "userPrivacySettingAllowChatInvites")
            .def(py::init<>());
    
    // A privacy setting for managing whether the user can be called
    py::class_<td_api::userPrivacySettingAllowCalls>(m, "userPrivacySettingAllowCalls")
            .def(py::init<>());
    
    // A privacy setting for managing whether peer-to-peer connections can be used for calls
    py::class_<td_api::userPrivacySettingAllowPeerToPeerCalls>(m, "userPrivacySettingAllowPeerToPeerCalls")
            .def(py::init<>());
    
    // A privacy setting for managing whether the user can be found by their phone number. Checked only if the phone number is not known to the other user. Can be set only to "Allow contacts" or "Allow all"
    py::class_<td_api::userPrivacySettingAllowFindingByPhoneNumber>(m, "userPrivacySettingAllowFindingByPhoneNumber")
            .def(py::init<>());
    
    // Contains information about the period of inactivity after which the current user's account will automatically be deleted @days Number of days of inactivity before the account will be flagged for deletion; should range from 30-366 days
    py::class_<td_api::accountTtl>(m, "accountTtl")
            .def(py::init<>())
    
            .def_readwrite("days", &td_api::accountTtl::days_);
    
    // Contains information about one session in a Telegram application used by the current user. Sessions should be shown to the user in the returned order
    py::class_<td_api::session>(m, "session")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::session::id_)
            .def_readwrite("is_current", &td_api::session::is_current_)
            .def_readwrite("is_password_pending", &td_api::session::is_password_pending_)
            .def_readwrite("api_id", &td_api::session::api_id_)
            .def_readwrite("application_name", &td_api::session::application_name_)
            .def_readwrite("application_version", &td_api::session::application_version_)
            .def_readwrite("is_official_application", &td_api::session::is_official_application_)
            .def_readwrite("device_model", &td_api::session::device_model_)
            .def_readwrite("platform", &td_api::session::platform_)
            .def_readwrite("system_version", &td_api::session::system_version_)
            .def_readwrite("log_in_date", &td_api::session::log_in_date_)
            .def_readwrite("last_active_date", &td_api::session::last_active_date_)
            .def_readwrite("ip", &td_api::session::ip_)
            .def_readwrite("country", &td_api::session::country_)
            .def_readwrite("region", &td_api::session::region_);
    
    // Contains a list of sessions @sessions List of sessions
    py::class_<td_api::sessions>(m, "sessions")
            .def(py::init<>())
    
            .def_readwrite("sessions", &td_api::sessions::sessions_);
    
    // Contains information about one website the current user is logged in with Telegram
    py::class_<td_api::connectedWebsite>(m, "connectedWebsite")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::connectedWebsite::id_)
            .def_readwrite("domain_name", &td_api::connectedWebsite::domain_name_)
            .def_readwrite("bot_user_id", &td_api::connectedWebsite::bot_user_id_)
            .def_readwrite("browser", &td_api::connectedWebsite::browser_)
            .def_readwrite("platform", &td_api::connectedWebsite::platform_)
            .def_readwrite("log_in_date", &td_api::connectedWebsite::log_in_date_)
            .def_readwrite("last_active_date", &td_api::connectedWebsite::last_active_date_)
            .def_readwrite("ip", &td_api::connectedWebsite::ip_)
            .def_readwrite("location", &td_api::connectedWebsite::location_);
    
    // Contains a list of websites the current user is logged in with Telegram @websites List of connected websites
    py::class_<td_api::connectedWebsites>(m, "connectedWebsites")
            .def(py::init<>())
    
            .def_readwrite("websites", &td_api::connectedWebsites::websites_);
    
    // The chat contains spam messages
    py::class_<td_api::chatReportReasonSpam>(m, "chatReportReasonSpam")
            .def(py::init<>());
    
    // The chat promotes violence
    py::class_<td_api::chatReportReasonViolence>(m, "chatReportReasonViolence")
            .def(py::init<>());
    
    // The chat contains pornographic messages
    py::class_<td_api::chatReportReasonPornography>(m, "chatReportReasonPornography")
            .def(py::init<>());
    
    // The chat has child abuse related content
    py::class_<td_api::chatReportReasonChildAbuse>(m, "chatReportReasonChildAbuse")
            .def(py::init<>());
    
    // The chat contains copyrighted content
    py::class_<td_api::chatReportReasonCopyright>(m, "chatReportReasonCopyright")
            .def(py::init<>());
    
    // The location-based chat is unrelated to its stated location
    py::class_<td_api::chatReportReasonUnrelatedLocation>(m, "chatReportReasonUnrelatedLocation")
            .def(py::init<>());
    
    // The chat represents a fake account
    py::class_<td_api::chatReportReasonFake>(m, "chatReportReasonFake")
            .def(py::init<>());
    
    // A custom reason provided by the user
    py::class_<td_api::chatReportReasonCustom>(m, "chatReportReasonCustom")
            .def(py::init<>());
    
    // The link is a link to the active sessions section of the app. Use getActiveSessions to handle the link
    py::class_<td_api::internalLinkTypeActiveSessions>(m, "internalLinkTypeActiveSessions")
            .def(py::init<>());
    
    // The link contains an authentication code. Call checkAuthenticationCode with the code if the current authorization state is authorizationStateWaitCode @code The authentication code
    py::class_<td_api::internalLinkTypeAuthenticationCode>(m, "internalLinkTypeAuthenticationCode")
            .def(py::init<>())
    
            .def_readwrite("code", &td_api::internalLinkTypeAuthenticationCode::code_);
    
    // The link is a link to a background. Call searchBackground with the given background name to process the link @background_name Name of the background
    py::class_<td_api::internalLinkTypeBackground>(m, "internalLinkTypeBackground")
            .def(py::init<>())
    
            .def_readwrite("background_name", &td_api::internalLinkTypeBackground::background_name_);
    
    // The link is a link to a chat with a Telegram bot. Call searchPublicChat with the given bot username, check that the user is a bot, show START button in the chat with the bot, and then call sendBotStartMessage with the given start parameter after the button is pressed
    py::class_<td_api::internalLinkTypeBotStart>(m, "internalLinkTypeBotStart")
            .def(py::init<>())
    
            .def_readwrite("bot_username", &td_api::internalLinkTypeBotStart::bot_username_)
            .def_readwrite("start_parameter", &td_api::internalLinkTypeBotStart::start_parameter_);
    
    // The link is a link to a Telegram bot, which is supposed to be added to a group chat. Call searchPublicChat with the given bot username, check that the user is a bot and can be added to groups, ask the current user to select a group to add the bot to, and then call sendBotStartMessage with the given start parameter and the chosen group chat. Bots can be added to a public group only by administrators of the group
    py::class_<td_api::internalLinkTypeBotStartInGroup>(m, "internalLinkTypeBotStartInGroup")
            .def(py::init<>())
    
            .def_readwrite("bot_username", &td_api::internalLinkTypeBotStartInGroup::bot_username_)
            .def_readwrite("start_parameter", &td_api::internalLinkTypeBotStartInGroup::start_parameter_);
    
    // The link is a link to the change phone number section of the app
    py::class_<td_api::internalLinkTypeChangePhoneNumber>(m, "internalLinkTypeChangePhoneNumber")
            .def(py::init<>());
    
    // The link is a chat invite link. Call checkChatInviteLink to process the link
    py::class_<td_api::internalLinkTypeChatInvite>(m, "internalLinkTypeChatInvite")
            .def(py::init<>());
    
    // The link is a link to the filter settings section of the app
    py::class_<td_api::internalLinkTypeFilterSettings>(m, "internalLinkTypeFilterSettings")
            .def(py::init<>());
    
    // The link is a link to a game. Call searchPublicChat with the given bot username, check that the user is a bot, ask the current user to select a group to send the game, and then call sendMessage with inputMessageGame
    py::class_<td_api::internalLinkTypeGame>(m, "internalLinkTypeGame")
            .def(py::init<>())
    
            .def_readwrite("bot_username", &td_api::internalLinkTypeGame::bot_username_)
            .def_readwrite("game_short_name", &td_api::internalLinkTypeGame::game_short_name_);
    
    // The link is a link to a language pack. Call getLanguagePackInfo with the given language pack identifier to process the link @language_pack_id Language pack identifier
    py::class_<td_api::internalLinkTypeLanguagePack>(m, "internalLinkTypeLanguagePack")
            .def(py::init<>())
    
            .def_readwrite("language_pack_id", &td_api::internalLinkTypeLanguagePack::language_pack_id_);
    
    // The link is a link to a Telegram message. Call getMessageLinkInfo to process the link
    py::class_<td_api::internalLinkTypeMessage>(m, "internalLinkTypeMessage")
            .def(py::init<>());
    
    // The link contains a message draft text. A share screen needs to be shown to the user, then the chosen chat should be open and the text should be added to the input field
    py::class_<td_api::internalLinkTypeMessageDraft>(m, "internalLinkTypeMessageDraft")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::internalLinkTypeMessageDraft::text_)
            .def_readwrite("contains_link", &td_api::internalLinkTypeMessageDraft::contains_link_);
    
    // The link contains a request of Telegram passport data. Call getPassportAuthorizationForm to process the link if the link was received outside of the app, otherwise ignore it
    py::class_<td_api::internalLinkTypePassportDataRequest>(m, "internalLinkTypePassportDataRequest")
            .def(py::init<>())
    
            .def_readwrite("bot_user_id", &td_api::internalLinkTypePassportDataRequest::bot_user_id_)
            .def_readwrite("scope", &td_api::internalLinkTypePassportDataRequest::scope_)
            .def_readwrite("public_key", &td_api::internalLinkTypePassportDataRequest::public_key_)
            .def_readwrite("nonce", &td_api::internalLinkTypePassportDataRequest::nonce_)
            .def_readwrite("callback_url", &td_api::internalLinkTypePassportDataRequest::callback_url_);
    
    // The link can be used to confirm ownership of a phone number to prevent account deletion. Call sendPhoneNumberConfirmationCode with the given hash and phone number to process the link
    py::class_<td_api::internalLinkTypePhoneNumberConfirmation>(m, "internalLinkTypePhoneNumberConfirmation")
            .def(py::init<>())
    
            .def_readwrite("hash", &td_api::internalLinkTypePhoneNumberConfirmation::hash_)
            .def_readwrite("phone_number", &td_api::internalLinkTypePhoneNumberConfirmation::phone_number_);
    
    // The link is a link to a proxy. Call addProxy to process the link and add the proxy
    py::class_<td_api::internalLinkTypeProxy>(m, "internalLinkTypeProxy")
            .def(py::init<>())
    
            .def_readwrite("server", &td_api::internalLinkTypeProxy::server_)
            .def_readwrite("port", &td_api::internalLinkTypeProxy::port_)
            .def_readwrite("type", &td_api::internalLinkTypeProxy::type_);
    
    // The link is a link to a chat by its username. Call searchPublicChat with the given chat username to process the link @chat_username Username of the chat
    py::class_<td_api::internalLinkTypePublicChat>(m, "internalLinkTypePublicChat")
            .def(py::init<>())
    
            .def_readwrite("chat_username", &td_api::internalLinkTypePublicChat::chat_username_);
    
    // The link can be used to login the current user on another device, but it must be scanned from QR-code using in-app camera. An alert similar to "This code can be used to allow someone to log in to your Telegram account. To confirm Telegram login, please go to Settings > Devices > Scan QR and scan the code" needs to be shown
    py::class_<td_api::internalLinkTypeQrCodeAuthentication>(m, "internalLinkTypeQrCodeAuthentication")
            .def(py::init<>());
    
    // The link is a link to app settings
    py::class_<td_api::internalLinkTypeSettings>(m, "internalLinkTypeSettings")
            .def(py::init<>());
    
    // The link is a link to a sticker set. Call searchStickerSet with the given sticker set name to process the link and show the sticker set @sticker_set_name Name of the sticker set
    py::class_<td_api::internalLinkTypeStickerSet>(m, "internalLinkTypeStickerSet")
            .def(py::init<>())
    
            .def_readwrite("sticker_set_name", &td_api::internalLinkTypeStickerSet::sticker_set_name_);
    
    // The link is a link to a theme. TDLib has no theme support yet @theme_name Name of the theme
    py::class_<td_api::internalLinkTypeTheme>(m, "internalLinkTypeTheme")
            .def(py::init<>())
    
            .def_readwrite("theme_name", &td_api::internalLinkTypeTheme::theme_name_);
    
    // The link is a link to the theme settings section of the app
    py::class_<td_api::internalLinkTypeThemeSettings>(m, "internalLinkTypeThemeSettings")
            .def(py::init<>());
    
    // The link is an unknown tg: link. Call getDeepLinkInfo to process the link
    py::class_<td_api::internalLinkTypeUnknownDeepLink>(m, "internalLinkTypeUnknownDeepLink")
            .def(py::init<>());
    
    // The link is a link to a voice chat. Call searchPublicChat with the given chat username, and then joinGoupCall with the given invite hash to process the link
    py::class_<td_api::internalLinkTypeVoiceChat>(m, "internalLinkTypeVoiceChat")
            .def(py::init<>())
    
            .def_readwrite("chat_username", &td_api::internalLinkTypeVoiceChat::chat_username_)
            .def_readwrite("invite_hash", &td_api::internalLinkTypeVoiceChat::invite_hash_);
    
    // Contains an HTTPS link to a message in a supergroup or channel @link Message link @is_public True, if the link will work for non-members of the chat
    py::class_<td_api::messageLink>(m, "messageLink")
            .def(py::init<>())
    
            .def_readwrite("link", &td_api::messageLink::link_)
            .def_readwrite("is_public", &td_api::messageLink::is_public_);
    
    // Contains information about a link to a message in a chat
    py::class_<td_api::messageLinkInfo>(m, "messageLinkInfo")
            .def(py::init<>())
    
            .def_readwrite("is_public", &td_api::messageLinkInfo::is_public_)
            .def_readwrite("chat_id", &td_api::messageLinkInfo::chat_id_)
            .def_readwrite("message", &td_api::messageLinkInfo::message_)
            .def_readwrite("media_timestamp", &td_api::messageLinkInfo::media_timestamp_)
            .def_readwrite("for_album", &td_api::messageLinkInfo::for_album_)
            .def_readwrite("for_comment", &td_api::messageLinkInfo::for_comment_);
    
    // Contains a part of a file @data File bytes
    py::class_<td_api::filePart>(m, "filePart")
            .def(py::init<>())
    
            .def_readwrite("data", &td_api::filePart::data_);
    
    // The data is not a file
    py::class_<td_api::fileTypeNone>(m, "fileTypeNone")
            .def(py::init<>());
    
    // The file is an animation
    py::class_<td_api::fileTypeAnimation>(m, "fileTypeAnimation")
            .def(py::init<>());
    
    // The file is an audio file
    py::class_<td_api::fileTypeAudio>(m, "fileTypeAudio")
            .def(py::init<>());
    
    // The file is a document
    py::class_<td_api::fileTypeDocument>(m, "fileTypeDocument")
            .def(py::init<>());
    
    // The file is a photo
    py::class_<td_api::fileTypePhoto>(m, "fileTypePhoto")
            .def(py::init<>());
    
    // The file is a profile photo
    py::class_<td_api::fileTypeProfilePhoto>(m, "fileTypeProfilePhoto")
            .def(py::init<>());
    
    // The file was sent to a secret chat (the file type is not known to the server)
    py::class_<td_api::fileTypeSecret>(m, "fileTypeSecret")
            .def(py::init<>());
    
    // The file is a thumbnail of a file from a secret chat
    py::class_<td_api::fileTypeSecretThumbnail>(m, "fileTypeSecretThumbnail")
            .def(py::init<>());
    
    // The file is a file from Secure storage used for storing Telegram Passport files
    py::class_<td_api::fileTypeSecure>(m, "fileTypeSecure")
            .def(py::init<>());
    
    // The file is a sticker
    py::class_<td_api::fileTypeSticker>(m, "fileTypeSticker")
            .def(py::init<>());
    
    // The file is a thumbnail of another file
    py::class_<td_api::fileTypeThumbnail>(m, "fileTypeThumbnail")
            .def(py::init<>());
    
    // The file type is not yet known
    py::class_<td_api::fileTypeUnknown>(m, "fileTypeUnknown")
            .def(py::init<>());
    
    // The file is a video
    py::class_<td_api::fileTypeVideo>(m, "fileTypeVideo")
            .def(py::init<>());
    
    // The file is a video note
    py::class_<td_api::fileTypeVideoNote>(m, "fileTypeVideoNote")
            .def(py::init<>());
    
    // The file is a voice note
    py::class_<td_api::fileTypeVoiceNote>(m, "fileTypeVoiceNote")
            .def(py::init<>());
    
    // The file is a wallpaper or a background pattern
    py::class_<td_api::fileTypeWallpaper>(m, "fileTypeWallpaper")
            .def(py::init<>());
    
    // Contains the storage usage statistics for a specific file type @file_type File type @size Total size of the files @count Total number of files
    py::class_<td_api::storageStatisticsByFileType>(m, "storageStatisticsByFileType")
            .def(py::init<>())
    
            .def_readwrite("file_type", &td_api::storageStatisticsByFileType::file_type_)
            .def_readwrite("size", &td_api::storageStatisticsByFileType::size_)
            .def_readwrite("count", &td_api::storageStatisticsByFileType::count_);
    
    // Contains the storage usage statistics for a specific chat @chat_id Chat identifier; 0 if none @size Total size of the files in the chat @count Total number of files in the chat @by_file_type Statistics split by file types
    py::class_<td_api::storageStatisticsByChat>(m, "storageStatisticsByChat")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::storageStatisticsByChat::chat_id_)
            .def_readwrite("size", &td_api::storageStatisticsByChat::size_)
            .def_readwrite("count", &td_api::storageStatisticsByChat::count_)
            .def_readwrite("by_file_type", &td_api::storageStatisticsByChat::by_file_type_);
    
    // Contains the exact storage usage statistics split by chats and file type @size Total size of files @count Total number of files @by_chat Statistics split by chats
    py::class_<td_api::storageStatistics>(m, "storageStatistics")
            .def(py::init<>())
    
            .def_readwrite("size", &td_api::storageStatistics::size_)
            .def_readwrite("count", &td_api::storageStatistics::count_)
            .def_readwrite("by_chat", &td_api::storageStatistics::by_chat_);
    
    // Contains approximate storage usage statistics, excluding files of unknown file type @files_size Approximate total size of files @file_count Approximate number of files
    py::class_<td_api::storageStatisticsFast>(m, "storageStatisticsFast")
            .def(py::init<>())
    
            .def_readwrite("files_size", &td_api::storageStatisticsFast::files_size_)
            .def_readwrite("file_count", &td_api::storageStatisticsFast::file_count_)
            .def_readwrite("database_size", &td_api::storageStatisticsFast::database_size_)
            .def_readwrite("language_pack_database_size", &td_api::storageStatisticsFast::language_pack_database_size_)
            .def_readwrite("log_size", &td_api::storageStatisticsFast::log_size_);
    
    // Contains database statistics
    py::class_<td_api::databaseStatistics>(m, "databaseStatistics")
            .def(py::init<>())
    
            .def_readwrite("statistics", &td_api::databaseStatistics::statistics_);
    
    // The network is not available
    py::class_<td_api::networkTypeNone>(m, "networkTypeNone")
            .def(py::init<>());
    
    // A mobile network
    py::class_<td_api::networkTypeMobile>(m, "networkTypeMobile")
            .def(py::init<>());
    
    // A mobile roaming network
    py::class_<td_api::networkTypeMobileRoaming>(m, "networkTypeMobileRoaming")
            .def(py::init<>());
    
    // A Wi-Fi network
    py::class_<td_api::networkTypeWiFi>(m, "networkTypeWiFi")
            .def(py::init<>());
    
    // A different network type (e.g., Ethernet network)
    py::class_<td_api::networkTypeOther>(m, "networkTypeOther")
            .def(py::init<>());
    
    // Contains information about the total amount of data that was used to send and receive files @file_type Type of the file the data is part of @network_type Type of the network the data was sent through. Call setNetworkType to maintain the actual network type
    py::class_<td_api::networkStatisticsEntryFile>(m, "networkStatisticsEntryFile")
            .def(py::init<>())
    
            .def_readwrite("file_type", &td_api::networkStatisticsEntryFile::file_type_)
            .def_readwrite("network_type", &td_api::networkStatisticsEntryFile::network_type_)
            .def_readwrite("sent_bytes", &td_api::networkStatisticsEntryFile::sent_bytes_)
            .def_readwrite("received_bytes", &td_api::networkStatisticsEntryFile::received_bytes_);
    
    // Contains information about the total amount of data that was used for calls @network_type Type of the network the data was sent through. Call setNetworkType to maintain the actual network type
    py::class_<td_api::networkStatisticsEntryCall>(m, "networkStatisticsEntryCall")
            .def(py::init<>())
    
            .def_readwrite("network_type", &td_api::networkStatisticsEntryCall::network_type_)
            .def_readwrite("sent_bytes", &td_api::networkStatisticsEntryCall::sent_bytes_)
            .def_readwrite("received_bytes", &td_api::networkStatisticsEntryCall::received_bytes_)
            .def_readwrite("duration", &td_api::networkStatisticsEntryCall::duration_);
    
    // A full list of available network statistic entries @since_date Point in time (Unix timestamp) from which the statistics are collected @entries Network statistics entries
    py::class_<td_api::networkStatistics>(m, "networkStatistics")
            .def(py::init<>())
    
            .def_readwrite("since_date", &td_api::networkStatistics::since_date_)
            .def_readwrite("entries", &td_api::networkStatistics::entries_);
    
    // Contains auto-download settings
    py::class_<td_api::autoDownloadSettings>(m, "autoDownloadSettings")
            .def(py::init<>())
    
            .def_readwrite("is_auto_download_enabled", &td_api::autoDownloadSettings::is_auto_download_enabled_)
            .def_readwrite("max_photo_file_size", &td_api::autoDownloadSettings::max_photo_file_size_)
            .def_readwrite("max_video_file_size", &td_api::autoDownloadSettings::max_video_file_size_)
            .def_readwrite("max_other_file_size", &td_api::autoDownloadSettings::max_other_file_size_)
            .def_readwrite("video_upload_bitrate", &td_api::autoDownloadSettings::video_upload_bitrate_)
            .def_readwrite("preload_large_videos", &td_api::autoDownloadSettings::preload_large_videos_)
            .def_readwrite("preload_next_audio", &td_api::autoDownloadSettings::preload_next_audio_)
            .def_readwrite("use_less_data_for_calls", &td_api::autoDownloadSettings::use_less_data_for_calls_);
    
    // Contains auto-download settings presets for the user
    py::class_<td_api::autoDownloadSettingsPresets>(m, "autoDownloadSettingsPresets")
            .def(py::init<>())
    
            .def_readwrite("low", &td_api::autoDownloadSettingsPresets::low_)
            .def_readwrite("medium", &td_api::autoDownloadSettingsPresets::medium_)
            .def_readwrite("high", &td_api::autoDownloadSettingsPresets::high_);
    
    // Currently waiting for the network to become available. Use setNetworkType to change the available network type
    py::class_<td_api::connectionStateWaitingForNetwork>(m, "connectionStateWaitingForNetwork")
            .def(py::init<>());
    
    // Currently establishing a connection with a proxy server
    py::class_<td_api::connectionStateConnectingToProxy>(m, "connectionStateConnectingToProxy")
            .def(py::init<>());
    
    // Currently establishing a connection to the Telegram servers
    py::class_<td_api::connectionStateConnecting>(m, "connectionStateConnecting")
            .def(py::init<>());
    
    // Downloading data received while the application was offline
    py::class_<td_api::connectionStateUpdating>(m, "connectionStateUpdating")
            .def(py::init<>());
    
    // There is a working connection to the Telegram servers
    py::class_<td_api::connectionStateReady>(m, "connectionStateReady")
            .def(py::init<>());
    
    // A category containing frequently used private chats with non-bot users
    py::class_<td_api::topChatCategoryUsers>(m, "topChatCategoryUsers")
            .def(py::init<>());
    
    // A category containing frequently used private chats with bot users
    py::class_<td_api::topChatCategoryBots>(m, "topChatCategoryBots")
            .def(py::init<>());
    
    // A category containing frequently used basic groups and supergroups
    py::class_<td_api::topChatCategoryGroups>(m, "topChatCategoryGroups")
            .def(py::init<>());
    
    // A category containing frequently used channels
    py::class_<td_api::topChatCategoryChannels>(m, "topChatCategoryChannels")
            .def(py::init<>());
    
    // A category containing frequently used chats with inline bots sorted by their usage in inline mode
    py::class_<td_api::topChatCategoryInlineBots>(m, "topChatCategoryInlineBots")
            .def(py::init<>());
    
    // A category containing frequently used chats used for calls
    py::class_<td_api::topChatCategoryCalls>(m, "topChatCategoryCalls")
            .def(py::init<>());
    
    // A category containing frequently used chats used to forward messages
    py::class_<td_api::topChatCategoryForwardChats>(m, "topChatCategoryForwardChats")
            .def(py::init<>());
    
    // A URL linking to a user @user_id Identifier of the user
    py::class_<td_api::tMeUrlTypeUser>(m, "tMeUrlTypeUser")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::tMeUrlTypeUser::user_id_);
    
    // A URL linking to a public supergroup or channel @supergroup_id Identifier of the supergroup or channel
    py::class_<td_api::tMeUrlTypeSupergroup>(m, "tMeUrlTypeSupergroup")
            .def(py::init<>())
    
            .def_readwrite("supergroup_id", &td_api::tMeUrlTypeSupergroup::supergroup_id_);
    
    // A chat invite link @info Chat invite link info
    py::class_<td_api::tMeUrlTypeChatInvite>(m, "tMeUrlTypeChatInvite")
            .def(py::init<>())
    
            .def_readwrite("info", &td_api::tMeUrlTypeChatInvite::info_);
    
    // A URL linking to a sticker set @sticker_set_id Identifier of the sticker set
    py::class_<td_api::tMeUrlTypeStickerSet>(m, "tMeUrlTypeStickerSet")
            .def(py::init<>())
    
            .def_readwrite("sticker_set_id", &td_api::tMeUrlTypeStickerSet::sticker_set_id_);
    
    // Represents a URL linking to an internal Telegram entity @url URL @type Type of the URL
    py::class_<td_api::tMeUrl>(m, "tMeUrl")
            .def(py::init<>())
    
            .def_readwrite("url", &td_api::tMeUrl::url_)
            .def_readwrite("type", &td_api::tMeUrl::type_);
    
    // Contains a list of t.me URLs @urls List of URLs
    py::class_<td_api::tMeUrls>(m, "tMeUrls")
            .def(py::init<>())
    
            .def_readwrite("urls", &td_api::tMeUrls::urls_);
    
    // Suggests the user to enable "archive_and_mute_new_chats_from_unknown_users" option
    py::class_<td_api::suggestedActionEnableArchiveAndMuteNewChats>(m, "suggestedActionEnableArchiveAndMuteNewChats")
            .def(py::init<>());
    
    // Suggests the user to check whether 2-step verification password is still remembered
    py::class_<td_api::suggestedActionCheckPassword>(m, "suggestedActionCheckPassword")
            .def(py::init<>());
    
    // Suggests the user to check whether authorization phone number is correct and change the phone number if it is inaccessible
    py::class_<td_api::suggestedActionCheckPhoneNumber>(m, "suggestedActionCheckPhoneNumber")
            .def(py::init<>());
    
    // Suggests the user to see a hint about meaning of one and two ticks on sent message
    py::class_<td_api::suggestedActionSeeTicksHint>(m, "suggestedActionSeeTicksHint")
            .def(py::init<>());
    
    // Suggests the user to convert specified supergroup to a broadcast group @supergroup_id Supergroup identifier
    py::class_<td_api::suggestedActionConvertToBroadcastGroup>(m, "suggestedActionConvertToBroadcastGroup")
            .def(py::init<>())
    
            .def_readwrite("supergroup_id", &td_api::suggestedActionConvertToBroadcastGroup::supergroup_id_);
    
    // Contains a counter @count Count
    py::class_<td_api::count>(m, "count")
            .def(py::init<>())
    
            .def_readwrite("count", &td_api::count::count_);
    
    // Contains some text @text Text
    py::class_<td_api::text>(m, "text")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::text::text_);
    
    // Contains a value representing a number of seconds @seconds Number of seconds
    py::class_<td_api::seconds>(m, "seconds")
            .def(py::init<>())
    
            .def_readwrite("seconds", &td_api::seconds::seconds_);
    
    // Contains information about a tg: deep link @text Text to be shown to the user @need_update_application True, if user should be asked to update the application
    py::class_<td_api::deepLinkInfo>(m, "deepLinkInfo")
            .def(py::init<>())
    
            .def_readwrite("text", &td_api::deepLinkInfo::text_)
            .def_readwrite("need_update_application", &td_api::deepLinkInfo::need_update_application_);
    
    // The text uses Markdown-style formatting
    py::class_<td_api::textParseModeMarkdown>(m, "textParseModeMarkdown")
            .def(py::init<>())
    
            .def_readwrite("version", &td_api::textParseModeMarkdown::version_);
    
    // The text uses HTML-style formatting. The same as Telegram Bot API "HTML" parse mode
    py::class_<td_api::textParseModeHTML>(m, "textParseModeHTML")
            .def(py::init<>());
    
    // A SOCKS5 proxy server @username Username for logging in; may be empty @password Password for logging in; may be empty
    py::class_<td_api::proxyTypeSocks5>(m, "proxyTypeSocks5")
            .def(py::init<>())
    
            .def_readwrite("username", &td_api::proxyTypeSocks5::username_)
            .def_readwrite("password", &td_api::proxyTypeSocks5::password_);
    
    // A HTTP transparent proxy server @username Username for logging in; may be empty @password Password for logging in; may be empty @http_only Pass true if the proxy supports only HTTP requests and doesn't support transparent TCP connections via HTTP CONNECT method
    py::class_<td_api::proxyTypeHttp>(m, "proxyTypeHttp")
            .def(py::init<>())
    
            .def_readwrite("username", &td_api::proxyTypeHttp::username_)
            .def_readwrite("password", &td_api::proxyTypeHttp::password_)
            .def_readwrite("http_only", &td_api::proxyTypeHttp::http_only_);
    
    // An MTProto proxy server @secret The proxy's secret in hexadecimal encoding
    py::class_<td_api::proxyTypeMtproto>(m, "proxyTypeMtproto")
            .def(py::init<>())
    
            .def_readwrite("secret", &td_api::proxyTypeMtproto::secret_);
    
    // Contains information about a proxy server @id Unique identifier of the proxy @server Proxy server IP address @port Proxy server port @last_used_date Point in time (Unix timestamp) when the proxy was last used; 0 if never @is_enabled True, if the proxy is enabled now @type Type of the proxy
    py::class_<td_api::proxy>(m, "proxy")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::proxy::id_)
            .def_readwrite("server", &td_api::proxy::server_)
            .def_readwrite("port", &td_api::proxy::port_)
            .def_readwrite("last_used_date", &td_api::proxy::last_used_date_)
            .def_readwrite("is_enabled", &td_api::proxy::is_enabled_)
            .def_readwrite("type", &td_api::proxy::type_);
    
    // Represents a list of proxy servers @proxies List of proxy servers
    py::class_<td_api::proxies>(m, "proxies")
            .def(py::init<>())
    
            .def_readwrite("proxies", &td_api::proxies::proxies_);
    
    // A static sticker in PNG format, which will be converted to WEBP server-side
    py::class_<td_api::inputStickerStatic>(m, "inputStickerStatic")
            .def(py::init<>())
    
            .def_readwrite("sticker", &td_api::inputStickerStatic::sticker_)
            .def_readwrite("emojis", &td_api::inputStickerStatic::emojis_)
            .def_readwrite("mask_position", &td_api::inputStickerStatic::mask_position_);
    
    // An animated sticker in TGS format
    py::class_<td_api::inputStickerAnimated>(m, "inputStickerAnimated")
            .def(py::init<>())
    
            .def_readwrite("sticker", &td_api::inputStickerAnimated::sticker_)
            .def_readwrite("emojis", &td_api::inputStickerAnimated::emojis_);
    
    // Represents a date range @start_date Point in time (Unix timestamp) at which the date range begins @end_date Point in time (Unix timestamp) at which the date range ends
    py::class_<td_api::dateRange>(m, "dateRange")
            .def(py::init<>())
    
            .def_readwrite("start_date", &td_api::dateRange::start_date_)
            .def_readwrite("end_date", &td_api::dateRange::end_date_);
    
    // A value with information about its recent changes @value The current value @previous_value The value for the previous day @growth_rate_percentage The growth rate of the value, as a percentage
    py::class_<td_api::statisticalValue>(m, "statisticalValue")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::statisticalValue::value_)
            .def_readwrite("previous_value", &td_api::statisticalValue::previous_value_)
            .def_readwrite("growth_rate_percentage", &td_api::statisticalValue::growth_rate_percentage_);
    
    // A graph data @json_data Graph data in JSON format @zoom_token If non-empty, a token which can be used to receive a zoomed in graph
    py::class_<td_api::statisticalGraphData>(m, "statisticalGraphData")
            .def(py::init<>())
    
            .def_readwrite("json_data", &td_api::statisticalGraphData::json_data_)
            .def_readwrite("zoom_token", &td_api::statisticalGraphData::zoom_token_);
    
    // The graph data to be asynchronously loaded through getStatisticalGraph @token The token to use for data loading
    py::class_<td_api::statisticalGraphAsync>(m, "statisticalGraphAsync")
            .def(py::init<>())
    
            .def_readwrite("token", &td_api::statisticalGraphAsync::token_);
    
    // An error message to be shown to the user instead of the graph @error_message The error message
    py::class_<td_api::statisticalGraphError>(m, "statisticalGraphError")
            .def(py::init<>())
    
            .def_readwrite("error_message", &td_api::statisticalGraphError::error_message_);
    
    // Contains statistics about interactions with a message
    py::class_<td_api::chatStatisticsMessageInteractionInfo>(m, "chatStatisticsMessageInteractionInfo")
            .def(py::init<>())
    
            .def_readwrite("message_id", &td_api::chatStatisticsMessageInteractionInfo::message_id_)
            .def_readwrite("view_count", &td_api::chatStatisticsMessageInteractionInfo::view_count_)
            .def_readwrite("forward_count", &td_api::chatStatisticsMessageInteractionInfo::forward_count_);
    
    // Contains statistics about messages sent by a user
    py::class_<td_api::chatStatisticsMessageSenderInfo>(m, "chatStatisticsMessageSenderInfo")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatStatisticsMessageSenderInfo::user_id_)
            .def_readwrite("sent_message_count", &td_api::chatStatisticsMessageSenderInfo::sent_message_count_)
            .def_readwrite("average_character_count", &td_api::chatStatisticsMessageSenderInfo::average_character_count_);
    
    // Contains statistics about administrator actions done by a user
    py::class_<td_api::chatStatisticsAdministratorActionsInfo>(m, "chatStatisticsAdministratorActionsInfo")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatStatisticsAdministratorActionsInfo::user_id_)
            .def_readwrite("deleted_message_count", &td_api::chatStatisticsAdministratorActionsInfo::deleted_message_count_)
            .def_readwrite("banned_user_count", &td_api::chatStatisticsAdministratorActionsInfo::banned_user_count_)
            .def_readwrite("restricted_user_count", &td_api::chatStatisticsAdministratorActionsInfo::restricted_user_count_);
    
    // Contains statistics about number of new members invited by a user
    py::class_<td_api::chatStatisticsInviterInfo>(m, "chatStatisticsInviterInfo")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::chatStatisticsInviterInfo::user_id_)
            .def_readwrite("added_member_count", &td_api::chatStatisticsInviterInfo::added_member_count_);
    
    // A detailed statistics about a supergroup chat
    py::class_<td_api::chatStatisticsSupergroup>(m, "chatStatisticsSupergroup")
            .def(py::init<>())
    
            .def_readwrite("period", &td_api::chatStatisticsSupergroup::period_)
            .def_readwrite("member_count", &td_api::chatStatisticsSupergroup::member_count_)
            .def_readwrite("message_count", &td_api::chatStatisticsSupergroup::message_count_)
            .def_readwrite("viewer_count", &td_api::chatStatisticsSupergroup::viewer_count_)
            .def_readwrite("sender_count", &td_api::chatStatisticsSupergroup::sender_count_)
            .def_readwrite("member_count_graph", &td_api::chatStatisticsSupergroup::member_count_graph_)
            .def_readwrite("join_graph", &td_api::chatStatisticsSupergroup::join_graph_)
            .def_readwrite("join_by_source_graph", &td_api::chatStatisticsSupergroup::join_by_source_graph_)
            .def_readwrite("language_graph", &td_api::chatStatisticsSupergroup::language_graph_)
            .def_readwrite("message_content_graph", &td_api::chatStatisticsSupergroup::message_content_graph_)
            .def_readwrite("action_graph", &td_api::chatStatisticsSupergroup::action_graph_)
            .def_readwrite("day_graph", &td_api::chatStatisticsSupergroup::day_graph_)
            .def_readwrite("week_graph", &td_api::chatStatisticsSupergroup::week_graph_)
            .def_readwrite("top_senders", &td_api::chatStatisticsSupergroup::top_senders_)
            .def_readwrite("top_administrators", &td_api::chatStatisticsSupergroup::top_administrators_)
            .def_readwrite("top_inviters", &td_api::chatStatisticsSupergroup::top_inviters_);
    
    // A detailed statistics about a channel chat
    py::class_<td_api::chatStatisticsChannel>(m, "chatStatisticsChannel")
            .def(py::init<>())
    
            .def_readwrite("period", &td_api::chatStatisticsChannel::period_)
            .def_readwrite("member_count", &td_api::chatStatisticsChannel::member_count_)
            .def_readwrite("mean_view_count", &td_api::chatStatisticsChannel::mean_view_count_)
            .def_readwrite("mean_share_count", &td_api::chatStatisticsChannel::mean_share_count_)
            .def_readwrite("enabled_notifications_percentage", &td_api::chatStatisticsChannel::enabled_notifications_percentage_)
            .def_readwrite("member_count_graph", &td_api::chatStatisticsChannel::member_count_graph_)
            .def_readwrite("join_graph", &td_api::chatStatisticsChannel::join_graph_)
            .def_readwrite("mute_graph", &td_api::chatStatisticsChannel::mute_graph_)
            .def_readwrite("view_count_by_hour_graph", &td_api::chatStatisticsChannel::view_count_by_hour_graph_)
            .def_readwrite("view_count_by_source_graph", &td_api::chatStatisticsChannel::view_count_by_source_graph_)
            .def_readwrite("join_by_source_graph", &td_api::chatStatisticsChannel::join_by_source_graph_)
            .def_readwrite("language_graph", &td_api::chatStatisticsChannel::language_graph_)
            .def_readwrite("message_interaction_graph", &td_api::chatStatisticsChannel::message_interaction_graph_)
            .def_readwrite("instant_view_interaction_graph", &td_api::chatStatisticsChannel::instant_view_interaction_graph_)
            .def_readwrite("recent_message_interactions", &td_api::chatStatisticsChannel::recent_message_interactions_);
    
    // A detailed statistics about a message @message_interaction_graph A graph containing number of message views and shares
    py::class_<td_api::messageStatistics>(m, "messageStatistics")
            .def(py::init<>())
    
            .def_readwrite("message_interaction_graph", &td_api::messageStatistics::message_interaction_graph_);
    
    // A point on a Cartesian plane @x The point's first coordinate @y The point's second coordinate
    py::class_<td_api::point>(m, "point")
            .def(py::init<>())
    
            .def_readwrite("x", &td_api::point::x_)
            .def_readwrite("y", &td_api::point::y_);
    
    // A straight line to a given point @end_point The end point of the straight line
    py::class_<td_api::vectorPathCommandLine>(m, "vectorPathCommandLine")
            .def(py::init<>())
    
            .def_readwrite("end_point", &td_api::vectorPathCommandLine::end_point_);
    
    // A cubic Bézier curve to a given point @start_control_point The start control point of the curve @end_control_point The end control point of the curve @end_point The end point of the curve
    py::class_<td_api::vectorPathCommandCubicBezierCurve>(m, "vectorPathCommandCubicBezierCurve")
            .def(py::init<>())
    
            .def_readwrite("start_control_point", &td_api::vectorPathCommandCubicBezierCurve::start_control_point_)
            .def_readwrite("end_control_point", &td_api::vectorPathCommandCubicBezierCurve::end_control_point_)
            .def_readwrite("end_point", &td_api::vectorPathCommandCubicBezierCurve::end_point_);
    
    // A scope covering all users
    py::class_<td_api::botCommandScopeDefault>(m, "botCommandScopeDefault")
            .def(py::init<>());
    
    // A scope covering all private chats
    py::class_<td_api::botCommandScopeAllPrivateChats>(m, "botCommandScopeAllPrivateChats")
            .def(py::init<>());
    
    // A scope covering all group and supergroup chats
    py::class_<td_api::botCommandScopeAllGroupChats>(m, "botCommandScopeAllGroupChats")
            .def(py::init<>());
    
    // A scope covering all group and supergroup chat administrators
    py::class_<td_api::botCommandScopeAllChatAdministrators>(m, "botCommandScopeAllChatAdministrators")
            .def(py::init<>());
    
    // A scope covering all members of a chat @chat_id Chat identifier
    py::class_<td_api::botCommandScopeChat>(m, "botCommandScopeChat")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::botCommandScopeChat::chat_id_);
    
    // A scope covering all administrators of a chat @chat_id Chat identifier
    py::class_<td_api::botCommandScopeChatAdministrators>(m, "botCommandScopeChatAdministrators")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::botCommandScopeChatAdministrators::chat_id_);
    
    // A scope covering a member of a chat @chat_id Chat identifier @user_id User identifier
    py::class_<td_api::botCommandScopeChatMember>(m, "botCommandScopeChatMember")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::botCommandScopeChatMember::chat_id_)
            .def_readwrite("user_id", &td_api::botCommandScopeChatMember::user_id_);
    
    // The user authorization state has changed @authorization_state New authorization state
    py::class_<td_api::updateAuthorizationState>(m, "updateAuthorizationState")
            .def(py::init<>())
    
            .def_readwrite("authorization_state", &td_api::updateAuthorizationState::authorization_state_);
    
    // A new message was received; can also be an outgoing message @message The new message
    py::class_<td_api::updateNewMessage>(m, "updateNewMessage")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::updateNewMessage::message_);
    
    // A request to send a message has reached the Telegram server. This doesn't mean that the message will be sent successfully or even that the send message request will be processed. This update will be sent only if the option "use_quick_ack" is set to true. This update may be sent multiple times for the same message
    py::class_<td_api::updateMessageSendAcknowledged>(m, "updateMessageSendAcknowledged")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageSendAcknowledged::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageSendAcknowledged::message_id_);
    
    // A message has been successfully sent @message Information about the sent message. Usually only the message identifier, date, and content are changed, but almost all other fields can also change @old_message_id The previous temporary message identifier
    py::class_<td_api::updateMessageSendSucceeded>(m, "updateMessageSendSucceeded")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::updateMessageSendSucceeded::message_)
            .def_readwrite("old_message_id", &td_api::updateMessageSendSucceeded::old_message_id_);
    
    // A message failed to send. Be aware that some messages being sent can be irrecoverably deleted, in which case updateDeleteMessages will be received instead of this update
    py::class_<td_api::updateMessageSendFailed>(m, "updateMessageSendFailed")
            .def(py::init<>())
    
            .def_readwrite("message", &td_api::updateMessageSendFailed::message_)
            .def_readwrite("old_message_id", &td_api::updateMessageSendFailed::old_message_id_)
            .def_readwrite("error_code", &td_api::updateMessageSendFailed::error_code_)
            .def_readwrite("error_message", &td_api::updateMessageSendFailed::error_message_);
    
    // The message content has changed @chat_id Chat identifier @message_id Message identifier @new_content New message content
    py::class_<td_api::updateMessageContent>(m, "updateMessageContent")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageContent::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageContent::message_id_)
            .def_readwrite("new_content", &td_api::updateMessageContent::new_content_);
    
    // A message was edited. Changes in the message content will come in a separate updateMessageContent @chat_id Chat identifier @message_id Message identifier @edit_date Point in time (Unix timestamp) when the message was edited @reply_markup New message reply markup; may be null
    py::class_<td_api::updateMessageEdited>(m, "updateMessageEdited")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageEdited::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageEdited::message_id_)
            .def_readwrite("edit_date", &td_api::updateMessageEdited::edit_date_)
            .def_readwrite("reply_markup", &td_api::updateMessageEdited::reply_markup_);
    
    // The message pinned state was changed @chat_id Chat identifier @message_id The message identifier @is_pinned True, if the message is pinned
    py::class_<td_api::updateMessageIsPinned>(m, "updateMessageIsPinned")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageIsPinned::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageIsPinned::message_id_)
            .def_readwrite("is_pinned", &td_api::updateMessageIsPinned::is_pinned_);
    
    // The information about interactions with a message has changed @chat_id Chat identifier @message_id Message identifier @interaction_info New information about interactions with the message; may be null
    py::class_<td_api::updateMessageInteractionInfo>(m, "updateMessageInteractionInfo")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageInteractionInfo::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageInteractionInfo::message_id_)
            .def_readwrite("interaction_info", &td_api::updateMessageInteractionInfo::interaction_info_);
    
    // The message content was opened. Updates voice note messages to "listened", video note messages to "viewed" and starts the TTL timer for self-destructing messages @chat_id Chat identifier @message_id Message identifier
    py::class_<td_api::updateMessageContentOpened>(m, "updateMessageContentOpened")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageContentOpened::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageContentOpened::message_id_);
    
    // A message with an unread mention was read @chat_id Chat identifier @message_id Message identifier @unread_mention_count The new number of unread mention messages left in the chat
    py::class_<td_api::updateMessageMentionRead>(m, "updateMessageMentionRead")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageMentionRead::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageMentionRead::message_id_)
            .def_readwrite("unread_mention_count", &td_api::updateMessageMentionRead::unread_mention_count_);
    
    // A message with a live location was viewed. When the update is received, the application is supposed to update the live location
    py::class_<td_api::updateMessageLiveLocationViewed>(m, "updateMessageLiveLocationViewed")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateMessageLiveLocationViewed::chat_id_)
            .def_readwrite("message_id", &td_api::updateMessageLiveLocationViewed::message_id_);
    
    // A new chat has been loaded/created. This update is guaranteed to come before the chat identifier is returned to the application. The chat field changes will be reported through separate updates @chat The chat
    py::class_<td_api::updateNewChat>(m, "updateNewChat")
            .def(py::init<>())
    
            .def_readwrite("chat", &td_api::updateNewChat::chat_);
    
    // The title of a chat was changed @chat_id Chat identifier @title The new chat title
    py::class_<td_api::updateChatTitle>(m, "updateChatTitle")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatTitle::chat_id_)
            .def_readwrite("title", &td_api::updateChatTitle::title_);
    
    // A chat photo was changed @chat_id Chat identifier @photo The new chat photo; may be null
    py::class_<td_api::updateChatPhoto>(m, "updateChatPhoto")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatPhoto::chat_id_)
            .def_readwrite("photo", &td_api::updateChatPhoto::photo_);
    
    // Chat permissions was changed @chat_id Chat identifier @permissions The new chat permissions
    py::class_<td_api::updateChatPermissions>(m, "updateChatPermissions")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatPermissions::chat_id_)
            .def_readwrite("permissions", &td_api::updateChatPermissions::permissions_);
    
    // The last message of a chat was changed. If last_message is null, then the last message in the chat became unknown. Some new unknown messages might be added to the chat in this case @chat_id Chat identifier @last_message The new last message in the chat; may be null @positions The new chat positions in the chat lists
    py::class_<td_api::updateChatLastMessage>(m, "updateChatLastMessage")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatLastMessage::chat_id_)
            .def_readwrite("last_message", &td_api::updateChatLastMessage::last_message_)
            .def_readwrite("positions", &td_api::updateChatLastMessage::positions_);
    
    // The position of a chat in a chat list has changed. Instead of this update updateChatLastMessage or updateChatDraftMessage might be sent @chat_id Chat identifier @position New chat position. If new order is 0, then the chat needs to be removed from the list
    py::class_<td_api::updateChatPosition>(m, "updateChatPosition")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatPosition::chat_id_)
            .def_readwrite("position", &td_api::updateChatPosition::position_);
    
    // A chat was marked as unread or was read @chat_id Chat identifier @is_marked_as_unread New value of is_marked_as_unread
    py::class_<td_api::updateChatIsMarkedAsUnread>(m, "updateChatIsMarkedAsUnread")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatIsMarkedAsUnread::chat_id_)
            .def_readwrite("is_marked_as_unread", &td_api::updateChatIsMarkedAsUnread::is_marked_as_unread_);
    
    // A chat was blocked or unblocked @chat_id Chat identifier @is_blocked New value of is_blocked
    py::class_<td_api::updateChatIsBlocked>(m, "updateChatIsBlocked")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatIsBlocked::chat_id_)
            .def_readwrite("is_blocked", &td_api::updateChatIsBlocked::is_blocked_);
    
    // A chat's has_scheduled_messages field has changed @chat_id Chat identifier @has_scheduled_messages New value of has_scheduled_messages
    py::class_<td_api::updateChatHasScheduledMessages>(m, "updateChatHasScheduledMessages")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatHasScheduledMessages::chat_id_)
            .def_readwrite("has_scheduled_messages", &td_api::updateChatHasScheduledMessages::has_scheduled_messages_);
    
    // A chat voice chat state has changed @chat_id Chat identifier @voice_chat New value of voice_chat
    py::class_<td_api::updateChatVoiceChat>(m, "updateChatVoiceChat")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatVoiceChat::chat_id_)
            .def_readwrite("voice_chat", &td_api::updateChatVoiceChat::voice_chat_);
    
    // The value of the default disable_notification parameter, used when a message is sent to the chat, was changed @chat_id Chat identifier @default_disable_notification The new default_disable_notification value
    py::class_<td_api::updateChatDefaultDisableNotification>(m, "updateChatDefaultDisableNotification")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatDefaultDisableNotification::chat_id_)
            .def_readwrite("default_disable_notification", &td_api::updateChatDefaultDisableNotification::default_disable_notification_);
    
    // Incoming messages were read or number of unread messages has been changed @chat_id Chat identifier @last_read_inbox_message_id Identifier of the last read incoming message @unread_count The number of unread messages left in the chat
    py::class_<td_api::updateChatReadInbox>(m, "updateChatReadInbox")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatReadInbox::chat_id_)
            .def_readwrite("last_read_inbox_message_id", &td_api::updateChatReadInbox::last_read_inbox_message_id_)
            .def_readwrite("unread_count", &td_api::updateChatReadInbox::unread_count_);
    
    // Outgoing messages were read @chat_id Chat identifier @last_read_outbox_message_id Identifier of last read outgoing message
    py::class_<td_api::updateChatReadOutbox>(m, "updateChatReadOutbox")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatReadOutbox::chat_id_)
            .def_readwrite("last_read_outbox_message_id", &td_api::updateChatReadOutbox::last_read_outbox_message_id_);
    
    // The chat unread_mention_count has changed @chat_id Chat identifier @unread_mention_count The number of unread mention messages left in the chat
    py::class_<td_api::updateChatUnreadMentionCount>(m, "updateChatUnreadMentionCount")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatUnreadMentionCount::chat_id_)
            .def_readwrite("unread_mention_count", &td_api::updateChatUnreadMentionCount::unread_mention_count_);
    
    // Notification settings for a chat were changed @chat_id Chat identifier @notification_settings The new notification settings
    py::class_<td_api::updateChatNotificationSettings>(m, "updateChatNotificationSettings")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatNotificationSettings::chat_id_)
            .def_readwrite("notification_settings", &td_api::updateChatNotificationSettings::notification_settings_);
    
    // Notification settings for some type of chats were updated @scope Types of chats for which notification settings were updated @notification_settings The new notification settings
    py::class_<td_api::updateScopeNotificationSettings>(m, "updateScopeNotificationSettings")
            .def(py::init<>())
    
            .def_readwrite("scope", &td_api::updateScopeNotificationSettings::scope_)
            .def_readwrite("notification_settings", &td_api::updateScopeNotificationSettings::notification_settings_);
    
    // The message Time To Live setting for a chat was changed @chat_id Chat identifier @message_ttl_setting New value of message_ttl_setting
    py::class_<td_api::updateChatMessageTtlSetting>(m, "updateChatMessageTtlSetting")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatMessageTtlSetting::chat_id_)
            .def_readwrite("message_ttl_setting", &td_api::updateChatMessageTtlSetting::message_ttl_setting_);
    
    // The chat action bar was changed @chat_id Chat identifier @action_bar The new value of the action bar; may be null
    py::class_<td_api::updateChatActionBar>(m, "updateChatActionBar")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatActionBar::chat_id_)
            .def_readwrite("action_bar", &td_api::updateChatActionBar::action_bar_);
    
    // The default chat reply markup was changed. Can occur because new messages with reply markup were received or because an old reply markup was hidden by the user
    py::class_<td_api::updateChatReplyMarkup>(m, "updateChatReplyMarkup")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatReplyMarkup::chat_id_)
            .def_readwrite("reply_markup_message_id", &td_api::updateChatReplyMarkup::reply_markup_message_id_);
    
    // A chat draft has changed. Be aware that the update may come in the currently opened chat but with old content of the draft. If the user has changed the content of the draft, this update shouldn't be applied @chat_id Chat identifier @draft_message The new draft message; may be null @positions The new chat positions in the chat lists
    py::class_<td_api::updateChatDraftMessage>(m, "updateChatDraftMessage")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatDraftMessage::chat_id_)
            .def_readwrite("draft_message", &td_api::updateChatDraftMessage::draft_message_)
            .def_readwrite("positions", &td_api::updateChatDraftMessage::positions_);
    
    // The list of chat filters or a chat filter has changed @chat_filters The new list of chat filters
    py::class_<td_api::updateChatFilters>(m, "updateChatFilters")
            .def(py::init<>())
    
            .def_readwrite("chat_filters", &td_api::updateChatFilters::chat_filters_);
    
    // The number of online group members has changed. This update with non-zero count is sent only for currently opened chats. There is no guarantee that it will be sent just after the count has changed @chat_id Identifier of the chat @online_member_count New number of online members in the chat, or 0 if unknown
    py::class_<td_api::updateChatOnlineMemberCount>(m, "updateChatOnlineMemberCount")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatOnlineMemberCount::chat_id_)
            .def_readwrite("online_member_count", &td_api::updateChatOnlineMemberCount::online_member_count_);
    
    // A notification was changed @notification_group_id Unique notification group identifier @notification Changed notification
    py::class_<td_api::updateNotification>(m, "updateNotification")
            .def(py::init<>())
    
            .def_readwrite("notification_group_id", &td_api::updateNotification::notification_group_id_)
            .def_readwrite("notification", &td_api::updateNotification::notification_);
    
    // A list of active notifications in a notification group has changed
    py::class_<td_api::updateNotificationGroup>(m, "updateNotificationGroup")
            .def(py::init<>())
    
            .def_readwrite("notification_group_id", &td_api::updateNotificationGroup::notification_group_id_)
            .def_readwrite("type", &td_api::updateNotificationGroup::type_)
            .def_readwrite("chat_id", &td_api::updateNotificationGroup::chat_id_)
            .def_readwrite("notification_settings_chat_id", &td_api::updateNotificationGroup::notification_settings_chat_id_)
            .def_readwrite("is_silent", &td_api::updateNotificationGroup::is_silent_)
            .def_readwrite("total_count", &td_api::updateNotificationGroup::total_count_)
            .def_readwrite("added_notifications", &td_api::updateNotificationGroup::added_notifications_)
            .def_readwrite("removed_notification_ids", &td_api::updateNotificationGroup::removed_notification_ids_);
    
    // Contains active notifications that was shown on previous application launches. This update is sent only if the message database is used. In that case it comes once before any updateNotification and updateNotificationGroup update @groups Lists of active notification groups
    py::class_<td_api::updateActiveNotifications>(m, "updateActiveNotifications")
            .def(py::init<>())
    
            .def_readwrite("groups", &td_api::updateActiveNotifications::groups_);
    
    // Describes whether there are some pending notification updates. Can be used to prevent application from killing, while there are some pending notifications
    py::class_<td_api::updateHavePendingNotifications>(m, "updateHavePendingNotifications")
            .def(py::init<>())
    
            .def_readwrite("have_delayed_notifications", &td_api::updateHavePendingNotifications::have_delayed_notifications_)
            .def_readwrite("have_unreceived_notifications", &td_api::updateHavePendingNotifications::have_unreceived_notifications_);
    
    // Some messages were deleted @chat_id Chat identifier @message_ids Identifiers of the deleted messages
    py::class_<td_api::updateDeleteMessages>(m, "updateDeleteMessages")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateDeleteMessages::chat_id_)
            .def_readwrite("message_ids", &td_api::updateDeleteMessages::message_ids_)
            .def_readwrite("is_permanent", &td_api::updateDeleteMessages::is_permanent_)
            .def_readwrite("from_cache", &td_api::updateDeleteMessages::from_cache_);
    
    // User activity in the chat has changed @chat_id Chat identifier @message_thread_id If not 0, a message thread identifier in which the action was performed @user_id Identifier of a user performing an action @action The action description
    py::class_<td_api::updateUserChatAction>(m, "updateUserChatAction")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateUserChatAction::chat_id_)
            .def_readwrite("message_thread_id", &td_api::updateUserChatAction::message_thread_id_)
            .def_readwrite("user_id", &td_api::updateUserChatAction::user_id_)
            .def_readwrite("action", &td_api::updateUserChatAction::action_);
    
    // The user went online or offline @user_id User identifier @status New status of the user
    py::class_<td_api::updateUserStatus>(m, "updateUserStatus")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::updateUserStatus::user_id_)
            .def_readwrite("status", &td_api::updateUserStatus::status_);
    
    // Some data of a user has changed. This update is guaranteed to come before the user identifier is returned to the application @user New data about the user
    py::class_<td_api::updateUser>(m, "updateUser")
            .def(py::init<>())
    
            .def_readwrite("user", &td_api::updateUser::user_);
    
    // Some data of a basic group has changed. This update is guaranteed to come before the basic group identifier is returned to the application @basic_group New data about the group
    py::class_<td_api::updateBasicGroup>(m, "updateBasicGroup")
            .def(py::init<>())
    
            .def_readwrite("basic_group", &td_api::updateBasicGroup::basic_group_);
    
    // Some data of a supergroup or a channel has changed. This update is guaranteed to come before the supergroup identifier is returned to the application @supergroup New data about the supergroup
    py::class_<td_api::updateSupergroup>(m, "updateSupergroup")
            .def(py::init<>())
    
            .def_readwrite("supergroup", &td_api::updateSupergroup::supergroup_);
    
    // Some data of a secret chat has changed. This update is guaranteed to come before the secret chat identifier is returned to the application @secret_chat New data about the secret chat
    py::class_<td_api::updateSecretChat>(m, "updateSecretChat")
            .def(py::init<>())
    
            .def_readwrite("secret_chat", &td_api::updateSecretChat::secret_chat_);
    
    // Some data from userFullInfo has been changed @user_id User identifier @user_full_info New full information about the user
    py::class_<td_api::updateUserFullInfo>(m, "updateUserFullInfo")
            .def(py::init<>())
    
            .def_readwrite("user_id", &td_api::updateUserFullInfo::user_id_)
            .def_readwrite("user_full_info", &td_api::updateUserFullInfo::user_full_info_);
    
    // Some data from basicGroupFullInfo has been changed @basic_group_id Identifier of a basic group @basic_group_full_info New full information about the group
    py::class_<td_api::updateBasicGroupFullInfo>(m, "updateBasicGroupFullInfo")
            .def(py::init<>())
    
            .def_readwrite("basic_group_id", &td_api::updateBasicGroupFullInfo::basic_group_id_)
            .def_readwrite("basic_group_full_info", &td_api::updateBasicGroupFullInfo::basic_group_full_info_);
    
    // Some data from supergroupFullInfo has been changed @supergroup_id Identifier of the supergroup or channel @supergroup_full_info New full information about the supergroup
    py::class_<td_api::updateSupergroupFullInfo>(m, "updateSupergroupFullInfo")
            .def(py::init<>())
    
            .def_readwrite("supergroup_id", &td_api::updateSupergroupFullInfo::supergroup_id_)
            .def_readwrite("supergroup_full_info", &td_api::updateSupergroupFullInfo::supergroup_full_info_);
    
    // Service notification from the server. Upon receiving this the application must show a popup with the content of the notification
    py::class_<td_api::updateServiceNotification>(m, "updateServiceNotification")
            .def(py::init<>())
    
            .def_readwrite("type", &td_api::updateServiceNotification::type_)
            .def_readwrite("content", &td_api::updateServiceNotification::content_);
    
    // Information about a file was updated @file New data about the file
    py::class_<td_api::updateFile>(m, "updateFile")
            .def(py::init<>())
    
            .def_readwrite("file", &td_api::updateFile::file_);
    
    // The file generation process needs to be started by the application
    py::class_<td_api::updateFileGenerationStart>(m, "updateFileGenerationStart")
            .def(py::init<>())
    
            .def_readwrite("generation_id", &td_api::updateFileGenerationStart::generation_id_)
            .def_readwrite("original_path", &td_api::updateFileGenerationStart::original_path_)
            .def_readwrite("destination_path", &td_api::updateFileGenerationStart::destination_path_)
            .def_readwrite("conversion", &td_api::updateFileGenerationStart::conversion_);
    
    // File generation is no longer needed @generation_id Unique identifier for the generation process
    py::class_<td_api::updateFileGenerationStop>(m, "updateFileGenerationStop")
            .def(py::init<>())
    
            .def_readwrite("generation_id", &td_api::updateFileGenerationStop::generation_id_);
    
    // New call was created or information about a call was updated @call New data about a call
    py::class_<td_api::updateCall>(m, "updateCall")
            .def(py::init<>())
    
            .def_readwrite("call", &td_api::updateCall::call_);
    
    // Information about a group call was updated @group_call New data about a group call
    py::class_<td_api::updateGroupCall>(m, "updateGroupCall")
            .def(py::init<>())
    
            .def_readwrite("group_call", &td_api::updateGroupCall::group_call_);
    
    // Information about a group call participant was changed. The updates are sent only after the group call is received through getGroupCall and only if the call is joined or being joined
    py::class_<td_api::updateGroupCallParticipant>(m, "updateGroupCallParticipant")
            .def(py::init<>())
    
            .def_readwrite("group_call_id", &td_api::updateGroupCallParticipant::group_call_id_)
            .def_readwrite("participant", &td_api::updateGroupCallParticipant::participant_);
    
    // New call signaling data arrived @call_id The call identifier @data The data
    py::class_<td_api::updateNewCallSignalingData>(m, "updateNewCallSignalingData")
            .def(py::init<>())
    
            .def_readwrite("call_id", &td_api::updateNewCallSignalingData::call_id_)
            .def_readwrite("data", &td_api::updateNewCallSignalingData::data_);
    
    // Some privacy setting rules have been changed @setting The privacy setting @rules New privacy rules
    py::class_<td_api::updateUserPrivacySettingRules>(m, "updateUserPrivacySettingRules")
            .def(py::init<>())
    
            .def_readwrite("setting", &td_api::updateUserPrivacySettingRules::setting_)
            .def_readwrite("rules", &td_api::updateUserPrivacySettingRules::rules_);
    
    // Number of unread messages in a chat list has changed. This update is sent only if the message database is used @chat_list The chat list with changed number of unread messages
    py::class_<td_api::updateUnreadMessageCount>(m, "updateUnreadMessageCount")
            .def(py::init<>())
    
            .def_readwrite("chat_list", &td_api::updateUnreadMessageCount::chat_list_)
            .def_readwrite("unread_count", &td_api::updateUnreadMessageCount::unread_count_)
            .def_readwrite("unread_unmuted_count", &td_api::updateUnreadMessageCount::unread_unmuted_count_);
    
    // Number of unread chats, i.e. with unread messages or marked as unread, has changed. This update is sent only if the message database is used
    py::class_<td_api::updateUnreadChatCount>(m, "updateUnreadChatCount")
            .def(py::init<>())
    
            .def_readwrite("chat_list", &td_api::updateUnreadChatCount::chat_list_)
            .def_readwrite("total_count", &td_api::updateUnreadChatCount::total_count_)
            .def_readwrite("unread_count", &td_api::updateUnreadChatCount::unread_count_)
            .def_readwrite("unread_unmuted_count", &td_api::updateUnreadChatCount::unread_unmuted_count_)
            .def_readwrite("marked_as_unread_count", &td_api::updateUnreadChatCount::marked_as_unread_count_)
            .def_readwrite("marked_as_unread_unmuted_count", &td_api::updateUnreadChatCount::marked_as_unread_unmuted_count_);
    
    // An option changed its value @name The option name @value The new option value
    py::class_<td_api::updateOption>(m, "updateOption")
            .def(py::init<>())
    
            .def_readwrite("name", &td_api::updateOption::name_)
            .def_readwrite("value", &td_api::updateOption::value_);
    
    // A sticker set has changed @sticker_set The sticker set
    py::class_<td_api::updateStickerSet>(m, "updateStickerSet")
            .def(py::init<>())
    
            .def_readwrite("sticker_set", &td_api::updateStickerSet::sticker_set_);
    
    // The list of installed sticker sets was updated @is_masks True, if the list of installed mask sticker sets was updated @sticker_set_ids The new list of installed ordinary sticker sets
    py::class_<td_api::updateInstalledStickerSets>(m, "updateInstalledStickerSets")
            .def(py::init<>())
    
            .def_readwrite("is_masks", &td_api::updateInstalledStickerSets::is_masks_)
            .def_readwrite("sticker_set_ids", &td_api::updateInstalledStickerSets::sticker_set_ids_);
    
    // The list of trending sticker sets was updated or some of them were viewed @sticker_sets The prefix of the list of trending sticker sets with the newest trending sticker sets
    py::class_<td_api::updateTrendingStickerSets>(m, "updateTrendingStickerSets")
            .def(py::init<>())
    
            .def_readwrite("sticker_sets", &td_api::updateTrendingStickerSets::sticker_sets_);
    
    // The list of recently used stickers was updated @is_attached True, if the list of stickers attached to photo or video files was updated, otherwise the list of sent stickers is updated @sticker_ids The new list of file identifiers of recently used stickers
    py::class_<td_api::updateRecentStickers>(m, "updateRecentStickers")
            .def(py::init<>())
    
            .def_readwrite("is_attached", &td_api::updateRecentStickers::is_attached_)
            .def_readwrite("sticker_ids", &td_api::updateRecentStickers::sticker_ids_);
    
    // The list of favorite stickers was updated @sticker_ids The new list of file identifiers of favorite stickers
    py::class_<td_api::updateFavoriteStickers>(m, "updateFavoriteStickers")
            .def(py::init<>())
    
            .def_readwrite("sticker_ids", &td_api::updateFavoriteStickers::sticker_ids_);
    
    // The list of saved animations was updated @animation_ids The new list of file identifiers of saved animations
    py::class_<td_api::updateSavedAnimations>(m, "updateSavedAnimations")
            .def(py::init<>())
    
            .def_readwrite("animation_ids", &td_api::updateSavedAnimations::animation_ids_);
    
    // The selected background has changed @for_dark_theme True, if background for dark theme has changed @background The new selected background; may be null
    py::class_<td_api::updateSelectedBackground>(m, "updateSelectedBackground")
            .def(py::init<>())
    
            .def_readwrite("for_dark_theme", &td_api::updateSelectedBackground::for_dark_theme_)
            .def_readwrite("background", &td_api::updateSelectedBackground::background_);
    
    // Some language pack strings have been updated @localization_target Localization target to which the language pack belongs @language_pack_id Identifier of the updated language pack @strings List of changed language pack strings
    py::class_<td_api::updateLanguagePackStrings>(m, "updateLanguagePackStrings")
            .def(py::init<>())
    
            .def_readwrite("localization_target", &td_api::updateLanguagePackStrings::localization_target_)
            .def_readwrite("language_pack_id", &td_api::updateLanguagePackStrings::language_pack_id_)
            .def_readwrite("strings", &td_api::updateLanguagePackStrings::strings_);
    
    // The connection state has changed. This update must be used only to show a human-readable description of the connection state @state The new connection state
    py::class_<td_api::updateConnectionState>(m, "updateConnectionState")
            .def(py::init<>())
    
            .def_readwrite("state", &td_api::updateConnectionState::state_);
    
    // New terms of service must be accepted by the user. If the terms of service are declined, then the deleteAccount method should be called with the reason "Decline ToS update" @terms_of_service_id Identifier of the terms of service @terms_of_service The new terms of service
    py::class_<td_api::updateTermsOfService>(m, "updateTermsOfService")
            .def(py::init<>())
    
            .def_readwrite("terms_of_service_id", &td_api::updateTermsOfService::terms_of_service_id_)
            .def_readwrite("terms_of_service", &td_api::updateTermsOfService::terms_of_service_);
    
    // The list of users nearby has changed. The update is guaranteed to be sent only 60 seconds after a successful searchChatsNearby request @users_nearby The new list of users nearby
    py::class_<td_api::updateUsersNearby>(m, "updateUsersNearby")
            .def(py::init<>())
    
            .def_readwrite("users_nearby", &td_api::updateUsersNearby::users_nearby_);
    
    // The list of supported dice emojis has changed @emojis The new list of supported dice emojis
    py::class_<td_api::updateDiceEmojis>(m, "updateDiceEmojis")
            .def(py::init<>())
    
            .def_readwrite("emojis", &td_api::updateDiceEmojis::emojis_);
    
    // The parameters of animation search through GetOption("animation_search_bot_username") bot has changed @provider Name of the animation search provider @emojis The new list of emojis suggested for searching
    py::class_<td_api::updateAnimationSearchParameters>(m, "updateAnimationSearchParameters")
            .def(py::init<>())
    
            .def_readwrite("provider", &td_api::updateAnimationSearchParameters::provider_)
            .def_readwrite("emojis", &td_api::updateAnimationSearchParameters::emojis_);
    
    // The list of suggested to the user actions has changed @added_actions Added suggested actions @removed_actions Removed suggested actions
    py::class_<td_api::updateSuggestedActions>(m, "updateSuggestedActions")
            .def(py::init<>())
    
            .def_readwrite("added_actions", &td_api::updateSuggestedActions::added_actions_)
            .def_readwrite("removed_actions", &td_api::updateSuggestedActions::removed_actions_);
    
    // A new incoming inline query; for bots only @id Unique query identifier @sender_user_id Identifier of the user who sent the query @user_location User location; may be null
    py::class_<td_api::updateNewInlineQuery>(m, "updateNewInlineQuery")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::updateNewInlineQuery::id_)
            .def_readwrite("sender_user_id", &td_api::updateNewInlineQuery::sender_user_id_)
            .def_readwrite("user_location", &td_api::updateNewInlineQuery::user_location_)
            .def_readwrite("chat_type", &td_api::updateNewInlineQuery::chat_type_)
            .def_readwrite("query", &td_api::updateNewInlineQuery::query_)
            .def_readwrite("offset", &td_api::updateNewInlineQuery::offset_);
    
    // The user has chosen a result of an inline query; for bots only @sender_user_id Identifier of the user who sent the query @user_location User location; may be null
    py::class_<td_api::updateNewChosenInlineResult>(m, "updateNewChosenInlineResult")
            .def(py::init<>())
    
            .def_readwrite("sender_user_id", &td_api::updateNewChosenInlineResult::sender_user_id_)
            .def_readwrite("user_location", &td_api::updateNewChosenInlineResult::user_location_)
            .def_readwrite("query", &td_api::updateNewChosenInlineResult::query_)
            .def_readwrite("result_id", &td_api::updateNewChosenInlineResult::result_id_)
            .def_readwrite("inline_message_id", &td_api::updateNewChosenInlineResult::inline_message_id_);
    
    // A new incoming callback query; for bots only @id Unique query identifier @sender_user_id Identifier of the user who sent the query
    py::class_<td_api::updateNewCallbackQuery>(m, "updateNewCallbackQuery")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::updateNewCallbackQuery::id_)
            .def_readwrite("sender_user_id", &td_api::updateNewCallbackQuery::sender_user_id_)
            .def_readwrite("chat_id", &td_api::updateNewCallbackQuery::chat_id_)
            .def_readwrite("message_id", &td_api::updateNewCallbackQuery::message_id_)
            .def_readwrite("chat_instance", &td_api::updateNewCallbackQuery::chat_instance_)
            .def_readwrite("payload", &td_api::updateNewCallbackQuery::payload_);
    
    // A new incoming callback query from a message sent via a bot; for bots only @id Unique query identifier @sender_user_id Identifier of the user who sent the query @inline_message_id Identifier of the inline message, from which the query originated
    py::class_<td_api::updateNewInlineCallbackQuery>(m, "updateNewInlineCallbackQuery")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::updateNewInlineCallbackQuery::id_)
            .def_readwrite("sender_user_id", &td_api::updateNewInlineCallbackQuery::sender_user_id_)
            .def_readwrite("inline_message_id", &td_api::updateNewInlineCallbackQuery::inline_message_id_)
            .def_readwrite("chat_instance", &td_api::updateNewInlineCallbackQuery::chat_instance_)
            .def_readwrite("payload", &td_api::updateNewInlineCallbackQuery::payload_);
    
    // A new incoming shipping query; for bots only. Only for invoices with flexible price @id Unique query identifier @sender_user_id Identifier of the user who sent the query @invoice_payload Invoice payload @shipping_address User shipping address
    py::class_<td_api::updateNewShippingQuery>(m, "updateNewShippingQuery")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::updateNewShippingQuery::id_)
            .def_readwrite("sender_user_id", &td_api::updateNewShippingQuery::sender_user_id_)
            .def_readwrite("invoice_payload", &td_api::updateNewShippingQuery::invoice_payload_)
            .def_readwrite("shipping_address", &td_api::updateNewShippingQuery::shipping_address_);
    
    // A new incoming pre-checkout query; for bots only. Contains full information about a checkout @id Unique query identifier @sender_user_id Identifier of the user who sent the query @currency Currency for the product price @total_amount Total price for the product, in the smallest units of the currency
    py::class_<td_api::updateNewPreCheckoutQuery>(m, "updateNewPreCheckoutQuery")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::updateNewPreCheckoutQuery::id_)
            .def_readwrite("sender_user_id", &td_api::updateNewPreCheckoutQuery::sender_user_id_)
            .def_readwrite("currency", &td_api::updateNewPreCheckoutQuery::currency_)
            .def_readwrite("total_amount", &td_api::updateNewPreCheckoutQuery::total_amount_)
            .def_readwrite("invoice_payload", &td_api::updateNewPreCheckoutQuery::invoice_payload_)
            .def_readwrite("shipping_option_id", &td_api::updateNewPreCheckoutQuery::shipping_option_id_)
            .def_readwrite("order_info", &td_api::updateNewPreCheckoutQuery::order_info_);
    
    // A new incoming event; for bots only @event A JSON-serialized event
    py::class_<td_api::updateNewCustomEvent>(m, "updateNewCustomEvent")
            .def(py::init<>())
    
            .def_readwrite("event", &td_api::updateNewCustomEvent::event_);
    
    // A new incoming query; for bots only @id The query identifier @data JSON-serialized query data @timeout Query timeout
    py::class_<td_api::updateNewCustomQuery>(m, "updateNewCustomQuery")
            .def(py::init<>())
    
            .def_readwrite("id", &td_api::updateNewCustomQuery::id_)
            .def_readwrite("data", &td_api::updateNewCustomQuery::data_)
            .def_readwrite("timeout", &td_api::updateNewCustomQuery::timeout_);
    
    // A poll was updated; for bots only @poll New data about the poll
    py::class_<td_api::updatePoll>(m, "updatePoll")
            .def(py::init<>())
    
            .def_readwrite("poll", &td_api::updatePoll::poll_);
    
    // A user changed the answer to a poll; for bots only @poll_id Unique poll identifier @user_id The user, who changed the answer to the poll @option_ids 0-based identifiers of answer options, chosen by the user
    py::class_<td_api::updatePollAnswer>(m, "updatePollAnswer")
            .def(py::init<>())
    
            .def_readwrite("poll_id", &td_api::updatePollAnswer::poll_id_)
            .def_readwrite("user_id", &td_api::updatePollAnswer::user_id_)
            .def_readwrite("option_ids", &td_api::updatePollAnswer::option_ids_);
    
    // User rights changed in a chat; for bots only @chat_id Chat identifier @actor_user_id Identifier of the user, changing the rights
    py::class_<td_api::updateChatMember>(m, "updateChatMember")
            .def(py::init<>())
    
            .def_readwrite("chat_id", &td_api::updateChatMember::chat_id_)
            .def_readwrite("actor_user_id", &td_api::updateChatMember::actor_user_id_)
            .def_readwrite("date", &td_api::updateChatMember::date_)
            .def_readwrite("invite_link", &td_api::updateChatMember::invite_link_)
            .def_readwrite("old_chat_member", &td_api::updateChatMember::old_chat_member_)
            .def_readwrite("new_chat_member", &td_api::updateChatMember::new_chat_member_);
    
    // Contains a list of updates @updates List of updates
    py::class_<td_api::updates>(m, "updates")
            .def(py::init<>())
    
            .def_readwrite("updates", &td_api::updates::updates_);
    
    // The log is written to stderr or an OS specific log
    py::class_<td_api::logStreamDefault>(m, "logStreamDefault")
            .def(py::init<>());
    
    // The log is written to a file
    py::class_<td_api::logStreamFile>(m, "logStreamFile")
            .def(py::init<>())
    
            .def_readwrite("path", &td_api::logStreamFile::path_)
            .def_readwrite("max_file_size", &td_api::logStreamFile::max_file_size_)
            .def_readwrite("redirect_stderr", &td_api::logStreamFile::redirect_stderr_);
    
    // The log is written nowhere
    py::class_<td_api::logStreamEmpty>(m, "logStreamEmpty")
            .def(py::init<>());
    
    // Contains a TDLib internal log verbosity level @verbosity_level Log verbosity level
    py::class_<td_api::logVerbosityLevel>(m, "logVerbosityLevel")
            .def(py::init<>())
    
            .def_readwrite("verbosity_level", &td_api::logVerbosityLevel::verbosity_level_);
    
    // Contains a list of available TDLib internal log tags @tags List of log tags
    py::class_<td_api::logTags>(m, "logTags")
            .def(py::init<>())
    
            .def_readwrite("tags", &td_api::logTags::tags_);
    
    // A simple object containing a number; for testing only @value Number
    py::class_<td_api::testInt>(m, "testInt")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::testInt::value_);
    
    // A simple object containing a string; for testing only @value String
    py::class_<td_api::testString>(m, "testString")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::testString::value_);
    
    // A simple object containing a sequence of bytes; for testing only @value Bytes
    py::class_<td_api::testBytes>(m, "testBytes")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::testBytes::value_);
    
    // A simple object containing a vector of numbers; for testing only @value Vector of numbers
    py::class_<td_api::testVectorInt>(m, "testVectorInt")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::testVectorInt::value_);
    
    // A simple object containing a vector of objects that hold a number; for testing only @value Vector of objects
    py::class_<td_api::testVectorIntObject>(m, "testVectorIntObject")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::testVectorIntObject::value_);
    
    // A simple object containing a vector of strings; for testing only @value Vector of strings
    py::class_<td_api::testVectorString>(m, "testVectorString")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::testVectorString::value_);
    
    // A simple object containing a vector of objects that hold a string; for testing only @value Vector of objects
    py::class_<td_api::testVectorStringObject>(m, "testVectorStringObject")
            .def(py::init<>())
    
            .def_readwrite("value", &td_api::testVectorStringObject::value_);
    

}