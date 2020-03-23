#ifndef COMMON_H
#define COMMON_H

enum ENUM_FILE_TYPE
{
    EMPTY_TYPE = 0,
    ACTIONSCRIPT_TYPE,
    ADVPL_PRW_TYPE,
    ANDROID_TYPE,
    ANGULAR_RESOLVER_TYPE,
    APIBLUEPRINT_TYPE,
    APPLESCRIPT_TYPE,
    APPVEYOR_TYPE,
    ASCIIDOC_TYPE,
    ASSEMBLY_TYPE,
    AUDIO_TYPE,
    AUTHORS_TYPE,
    AUTOHOTKEY_TYPE,
    AUTOIT_TYPE,
    AZURE_PIPELINES_TYPE,
    AZURE_TYPE,
    BABEL_TYPE,
    BALLERINA_TYPE,
    BAZEL_TYPE,
    BITHOUND_TYPE,
    BLINK_TYPE,
    BLINK_LIGHT_TYPE,
    BOWER_TYPE,
    BROWSERLIST_TYPE,
    BROWSERLIST_LIGHT_TYPE,
    BUCKLESCRIPT_TYPE,
    BUILDKITE_TYPE,
    C_TYPE,
    CAKE_TYPE,
    CERTIFICATE_TYPE,
    CHANGELOG_TYPE,
    CIRCLECI_TYPE,
    CIRCLECI_LIGHT_TYPE,
    CLOJURE_TYPE,
    CMAKE_TYPE,
    CODE_CLIMATE_LIGHT_TYPE,
    CODECOV_TYPE,
    CODEOWNERS_TYPE,
    COFFEE_TYPE,
    COLDFUSION_TYPE,
    CONDUCT_TYPE,
    CONSOLE_TYPE,
    CONTRIBUTING_TYPE,
    CPP_TYPE,
    CREDITS_TYPE,
    CRYSTAL_LIGHT_TYPE,
    CSHARP_TYPE,
    CSS_MAP_TYPE,
    CSS_TYPE,
    CUCUMBER_TYPE,
    CUDA_TYPE,
    D_TYPE,
    DART_TYPE,
    DATABASE_TYPE,
    DIFF_TYPE,
    DISC_TYPE,
    DJANGO_TYPE,
    DOCUMENT_TYPE,
    DRONE_LIGHT_TYPE,
    EDGE_TYPE,
    EJS_TYPE,
    ELIXIR_TYPE,
    ELM_TYPE,
    EMAIL_TYPE,
    ERLANG_TYPE,
    ESLINT_TYPE,
    EXCEL_TYPE,
    EXE_TYPE,
    FASTLANE_TYPE,
    FAVICON_TYPE,
    FILE_TYPE,
    FIREBASE_TYPE,
    FLOW_TYPE,
    FOLDER_ANDROID_TYPE,
    FOLDER_AUDIO_TYPE,
    FOLDER_AWS_TYPE,
    FOLDER_BATCH_OPEN_TYPE,
    FOLDER_CI_OPEN_TYPE,
    FOLDER_CI_TYPE,
    FOLDER_CIRCLECI_OPEN_TYPE,
    FOLDER_CIRCLECI_TYPE,
    FOLDER_CLIENT_TYPE,
    FOLDER_COMMAND_TYPE,
    FOLDER_COMPONENTS_TYPE,
    FOLDER_CONFIG_TYPE,
    FOLDER_CUSTOM_TYPE,
    FOLDER_DOCS_TYPE,
    FOLDER_TYPE,
    FONT_TYPE,
    FORTRAN_TYPE,
    FOXPRO_TYPE,
    FSHARP_TYPE,
    FUSEBOX_TYPE,
    GATSBY_TYPE,
    GCP_TYPE,
    GEMFILE_TYPE,
    GIT_TYPE,
    GITLAB_TYPE,
    GITPOD_TYPE,
    GO_MOD_TYPE,
    GO_TYPE,
    GODOT_ASSETS_TYPE,
    GODOT_TYPE,
    GO_GOPHER_TYPE,
    GRADLE_TYPE,
    GRAPHCOOL_TYPE,
    GRAPHQL_TYPE,
    GROOVY_TYPE,
    GRUNT_TYPE,
    GULP_TYPE,
    H_TYPE,
    HACK_TYPE,
    HAML_TYPE,
    HANDLEBARS_TYPE,
    HASKELL_TYPE,
    HAXE_TYPE,
    HCL_LIGHT_TYPE,
    HELM_TYPE,
    HEROKU_TYPE,
    HPP_TYPE,
    HTML_TYPE,
    HTTP_TYPE,
    HUSKY_TYPE,
    IMAGE_TYPE,
    IN_TYPE,
    IONIC_TYPE,
    ISTANBUL_TYPE,
    JAVA_TYPE,
    JAVASCRIPT_MAP_TYPE,
    JAVASCRIPT_TYPE,
    JEST_TYPE,
    JINJA_LIGHT_TYPE,
    JSON_TYPE,
    JULIA_TYPE,
    JUPYTER_TYPE,
    KARMA_TYPE,
    KEY_TYPE,
    KIVY_TYPE,
    KL_TYPE,
    LARAVEL_TYPE,
    LESS_TYPE,
    LIB_TYPE,
    LIQUID_TYPE,
    LIVESCRIPT_TYPE,
    LOCK_TYPE,
    LOG_TYPE,
    LUA_TYPE,
    MAKEFILE_TYPE,
    MARKDOWN_TYPE,
    MARKOJS_TYPE,
    MATHEMATICA_TYPE,
    MATLAB_TYPE,
    MDX_TYPE,
    MERLIN_TYPE,
    MINT_TYPE,
    MJML_TYPE,
    MOCHA_TYPE,
    MOONSCRIPT_TYPE,
    MXML_TYPE,
    NEST_CONTROLLER_TYPE,
    NEST_SERVICE_TYPE,
    NETLIFY_TYPE,
    NGRX_ACTIONS_TYPE,
    NIM_TYPE,
    NIX_TYPE,
    NODEJS_TYPE,
    NPM_TYPE,
    NUNJUCKS_TYPE,
    NUXT_TYPE,
    OUTLOOK_TYPE,
    PDF_TYPE,
    PERCY_TYPE,
    PERL_TYPE,
    PHP_TYPE,
    PHP_ELEPHANT_TYPE,
    POSTCSS_TYPE,
    POWERPOINT_TYPE,
    POWERSHELL_TYPE,
    PRISMA_TYPE,
    PROCESSING_LIGHT_TYPE,
    PROLOG_TYPE,
    PUG_TYPE,
    PUPPET_TYPE,
    PURESCRIPT_TYPE,
    PYTHON_MISC_TYPE,
    PYTHON_TYPE,
    QSHARP_TYPE,
    R_TYPE,
    RACKET_TYPE,
    RAML_TYPE,
    RAZOR_TYPE,
    REACT_TYPE,
    REACT_TS_TYPE,
    README_TYPE,
    REASON_TYPE,
    RED_TYPE,
    REDUX_ACTION_TYPE,
    REDUX_REDUCER_TYPE,
    REDUX_STORE_TYPE,
    RESTQL_TYPE,
    RIOT_TYPE,
    ROBOT_TYPE,
    ROUTING_TYPE,
    RUBY_TYPE,
    RUST_TYPE,
    SAN_TYPE,
    SASS_TYPE,
    SBT_TYPE,
    SCALA_TYPE,
    SCHEME_TYPE,
    SEMANTIC_RELEASE_TYPE,
    SEMANTIC_RELEASE_LIGHT_TYPE,
    SEQUELIZE_TYPE,
    SETTINGS_TYPE,
    SHADERLAB_TYPE,
    SILVERSTRIPE_TYPE,
    SLIM_TYPE,
    SMARTY_TYPE,
    SNYK_TYPE,
    SOLIDITY_TYPE,
    STENCIL_TYPE,
    STENCIL_LIGHT_TYPE,
    STORYBOOK_TYPE,
    STYLELINT_TYPE,
    STYLELINT_LIGHT_TYPE,
    STYLUS_TYPE,
    SUBLIME_TYPE,
    SVELTE_TYPE,
    SVG_TYPE,
    SWIFT_TYPE,
    TABLE_TYPE,
    TAILWINDCSS_TYPE,
    TERRAFORM_TYPE,
    TEST_JS_TYPE,
    TEST_JSX_TYPE,
    TEST_TS_TYPE,
    TEX_TYPE,
    TODO_TYPE,
    TRAVIS_TYPE,
    TUNE_TYPE,
    TWIG_TYPE,
    TYPESCRIPT_DEF_TYPE,
    TYPESCRIPT_TYPE,
    URL_TYPE,
    VAGRANT_TYPE,
    VELOCITY_TYPE,
    VERILOG_TYPE,
    VIDEO_TYPE,
    VIM_TYPE,
    VIRTUAL_TYPE,
    VISUALSTUDIO_TYPE,
    VSCODE_TYPE,
    VUE_CONFIG_TYPE,
    VUE_TYPE,
    VUEX_STORE_TYPE,
    WAKATIME_TYPE,
    WAKATIME_LIGHT_TYPE,
    WALLABY_TYPE,
    WATCHMAN_TYPE,
    WEBASSEMBLY_TYPE,
    WEBHINT_TYPE,
    WEBPACK_TYPE,
    WEPY_TYPE,
    WOLFRAMLANGUAGE_TYPE,
    WORD_TYPE,
    WORD_1_TYPE,
    XAML_TYPE,
    XML_TYPE,
    YAML_TYPE,
    YANG_TYPE,
    YARN_TYPE,
    YELLOWFOLDER_TYPE,
    YELLOWFOLDER_1_TYPE,
    ZIG_TYPE,
    ZIP_TYPE
};

#endif // COMMON_H
